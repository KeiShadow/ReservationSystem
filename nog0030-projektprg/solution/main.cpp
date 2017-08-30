//! \file main.cpp
//! \brief Main soubor s menu.
//! \author Petr Noga
//! \version 2
//! \date 20. December 2015
#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <time.h>
#include <cstdlib>
#include "functions.h"
using namespace std;



int main()
{
	reservation *res = new reservation[count("../vstupnidata/res.csv")];
	rooms *room = new rooms[count("../vstupnidata/room.csv")];
	string fileRes = "../vstupnidata/res.csv";
	string fileRoom = "../vstupnidata/room.csv";
	ReadRes(fileRes, res);
	ReadRoom(fileRoom, room);
mine:cout << "      Vitejte v menu rezervaci" << endl;
	cout << "############[&&&&&&&&&&&&&]###############" << endl;
	cout << " Vyberte jednu z moznosti: " << endl;
	cout << "   |1: Vypis vsech mistnosti." << endl;
	cout << "   |2: Vypis volnych mistnosti." << endl;
	cout << "   |3: Volne mistnosti podle ceny." << endl;
	cout << "   |4: Volne mistnosti podle datumu." << endl;
	cout << "   |5: Rezervace." << endl;
	cout << "   |6: Export rezervaci do HTML souboru." << endl;
	cout << "   |7: Ukoncit program." << endl;
	cout << "############[&&&&&&&&&&&&&]###############" << endl;
	cout << "Zadejte volbu z menu od 1-6:" << endl;
	int cislo;
	cin >> cislo;
	if (testInput(cislo)) {
		if ((cislo <= 0) || (cislo > 7)) {
			system("cls");
			cin.clear();
			cin.ignore();
			cout << "Budete presmerovani zpet do menu" << endl;
			goto mine;
		}

	}

	switch (cislo) {
	    case 1: {
		AllRoom(fileRoom,fileRes,room,res);
		cout << "Chcete zpet do menu? y/n" << endl;
		char v;
		cin >> v;
		if (v == 'Y' || v == 'y') {
			system("cls");
			goto mine;
		}
		else return 1;
     return 0;
	};
	case 2: {
		FreeRoom(fileRoom, room);
		cout << "Chcete zpet do menu? y/n" << endl;
		char v;
		cin >> v;
		if (v == 'Y' || v == 'y') {
			system("cls");
			goto mine;
		}
		else return 1;
     return 0;
	};
	case 3: {
		int cena;
		system("cls");
backCena:cout << "Zadejte cenu, zakladni cena mistnosti je 100kc." << endl;
		cin >> cena;
		if (testCena(cena)) {
			if (cena < 100) {
				system("cls");
				cin.clear();
				cin.ignore();
				cout << "Zadal jste cenu mensi nez 100Kc, nebo jste zadal slovo nebo pismeno." << endl
					<< "Chcete zadat novou cenu? y/n " << endl;
				char v;
				cin >> v;
				if (v == 'Y' || v == 'y') {
					system("cls");
					goto backCena;
				}
				else goto mine;
			}
		}
		PrizeByFreeRoom(fileRoom, cena, room);
		cout << "Chcete zpet do menu? y/n" << endl;
		char v;
		cin >> v;
		if (v == 'Y' || v == 'y') {
			system("cls");
			goto mine;
		}
		else return 1;
	};
	case 4: {
		DateByFreeRoom(fileRoom, fileRes,room, res);
		cout << "Chcete zpet do menu? y/n" << endl;
		char v;
		cin >> v;
		if (v == 'Y' || v == 'y') {
			system("cls");
			goto mine;
		}
		else return 1;
	};
	case 5: {
		ResByDate(fileRoom, fileRes, room, res);
		cout << "Chcete zpet do menu? y/n" << endl;
		char v;
		cin >> v;
		if (v == 'Y' || v == 'y') {
			system("cls");
			goto mine;
		}
		else return 1;
		return 0;
	};
	case 6: {
		ExportToHtml(fileRoom, fileRes, room, res);
		cout << "Chcete zpet do menu? y/n" << endl;
		char v;
		cin >> v;
		if (v == 'Y' || v == 'y') {
			system("cls");
			goto mine;
		}
		else return 1;
		return 0;
	};
	case 7: {
		cout << "Program ukoncen." << endl;
		return 0;
	};
	}
 return 0;
}
