//! \file functions.cpp
//! \brief Hlavickovy soubor dokumentu s deklaracemi vsech funkci
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

bool ValidDate(string date){
	char del1, del2;
	int day, month, year;
	time_t rawtime = time(0);
	struct tm * timeinfo;
	time(&rawtime);

	timeinfo = localtime(&rawtime);

	int currentyear = timeinfo->tm_year + 1900;
	int currentmonth = timeinfo->tm_mon + 1;
	int currentday = timeinfo->tm_mday;

	for (unsigned int i = 0; i < date.length(); i++)
	{
		if ((date[i] >= '0' && date[i] <= '9') || date[i] == '.')
		{
			stringstream ss(date);
			ss >> day >> del1 >> month >> del2 >> year;
			if (del1 != del2 || del1 != '/' || del1 != '/') return false;
			if (year < currentyear) return false;
			if (year == currentyear && currentmonth > month) return false;
			if (year == currentyear && currentmonth == month && currentday > day) return false;
			switch (month)
			{
			case 1:
				if (day < 1 || day > 31) return false;
				else return true;
				break;
			case 2:
				if (year % 4 == 0)
				{
					if (day < 1 || day > 29) return false;
					else return true;
				}
				else
				{
					if (day < 1 || day > 28) return false;
					else return true;
				}
				break;
			case 3:
				if (day < 1 || day > 31) return false;
				else return true;
				break;
			case 4:
				if (day < 1 || day > 30) return false;
				else return true;
				break;
			case 5:
				if (day < 1 || day > 31) return false;
				else return true;
				break;
			case 6:
				if (day < 1 || day > 30) return false;
				else return true;
				break;
			case 7:
				if (day < 1 || day > 31) return false;
				else return true;
				break;
			case 8:
				if (day < 1 || day > 31) return false;
				else return true;
				break;
			case 9:
				if (day < 1 || day > 30) return false;
				else return true;
				break;
			case 10:
				if (day < 1 || day > 31) return false;
				else return true;
				break;
			case 11:
				if (day < 1 || day > 30) return false;
				else return true;
				break;
			case 12:
				if (day < 1 || day > 31) return false;
				else return true;
				break;
			default:
				return false;
				break;
			}
		}
		else return false;
	}
	return true;
}

int count(string fileName) {
	int i = 0;
	string line;
	ifstream file(fileName);
	while (getline(file, line, '\n')) {
		i++;
	}
	return i;
}
void ReadRoom(string fileName, rooms *x) {
	int i = 0;
	char del1, del2, del3, del4, del5;
	string line;
	ifstream file(fileName);
	while (!file.eof()) {
		getline(file, line);
		stringstream lineStreamRoom(line);
		lineStreamRoom >> x[i].ID >> del1 >> x[i].floor >> del2 >> x[i].numOfRoom >> del3 >> x[i].freeCapacity >> del4 >> x[i].capacity >> del5 >> x[i].prizePerDay;
		i++;
	}
	file.close();
}

void ReadRes(string fileName, reservation *y) {
	int i = 0;
	char del1;
	string line;
	ifstream file(fileName);

	while (!file.eof()) {
		getline(file, line);
		stringstream lineStreamRes(line);
		lineStreamRes >> y[i].ID >> del1 >> y[i].date;
		i++;
	}
	file.close();
}

void AllRoom(string fileNameRoom, string fileNameRes ,rooms *x, reservation *y){
 system("cls");
 ifstream fileRoom(fileNameRoom);
 ifstream fileRes(fileNameRes);
 for (int i = 0; i<count(fileNameRoom) && count(fileNameRes); i++) {
        if(x[i].ID==y[i].ID){
			cout << "ID:" << x[i].ID << " poschodi: " << x[i].floor << " C. mistnosti: "
				<< x[i].numOfRoom << " volna sedadla: " << x[i].freeCapacity <<
				" pocet sedadel: " << x[i].capacity << " cena za den: " << x[i].prizePerDay << " datum rezervace: " << y[i].date <<endl;
    }
}
fileRoom.close();
fileRes.close();
}

void FreeRoom(string fileNameRoom, rooms *x) {
    system("cls");
	ifstream fileRoom(fileNameRoom);

	for (int i = 0; i<count(fileNameRoom); i++) {
		if (x[i].freeCapacity != 0) {
			cout << "ID:" << x[i].ID << " poschodi: " << x[i].floor << " C. mistnosti: "
				<< x[i].numOfRoom << " volna sedadla: " << x[i].freeCapacity <<
				" pocet sedadel: " << x[i].capacity << " cena za den: " << x[i].prizePerDay << endl;
		}

	}
	fileRoom.close();
}
void PrizeByFreeRoom(string fileNameRoom, int cena, rooms *x) {
	system("cls");
	ifstream fileRoom(fileNameRoom);
	for (int i = 0; i<count(fileNameRoom); i++) {
		if ((x[i].freeCapacity != 0) && (x[i].prizePerDay <= cena)) {
			cout << "ID:" << x[i].ID << " poschodi: " << x[i].floor << " C. mistnosti: "
				<< x[i].numOfRoom << " volna sedadla: " << x[i].freeCapacity <<
				" pocet sedadel: " << x[i].capacity << " cena za den: " << x[i].prizePerDay << endl;
		}
	}
	fileRoom.close();
}
void DateByFreeRoom(string fileNameRoom, string fileNameRes, rooms *x, reservation *y) {
	ifstream fileRoom(fileNameRoom);
	ifstream fileRes(fileNameRes);
	system("cls");
backdate:cout << "Zadejte datum od aktulaniho data ve formatu dd/mm/yyyy: " << endl;
   string datum;
   cin >> datum;
   if(ValidDate(datum)){
	for (int i = 0; i<count(fileNameRoom) ; i++) {
     for(int j=0; j< count(fileNameRes); j++){
		if (y[j].date == datum && y[j].ID== x[i].ID && x[i].freeCapacity != 0){
			cout << "ID:" << x[i].ID << " poschodi: " << x[i].floor << " C. mistnosti: "
				<< x[i].numOfRoom << " volna sedadla: " << x[i].freeCapacity <<
				" pocet sedadel: " << x[i].capacity << " cena za den: " << x[i].prizePerDay
				<< " datum: " << y[j].date << endl;
	 }
	 }
	}
   }else {
    cout << "Spatne zadane datum, bude te presmerovani zpet k zadani data." << endl;
    goto backdate;
   }
	fileRoom.close();
	fileRes.close();
}

void ResByDate(string fileNameRoom, string fileNameRes, rooms *x, reservation *y) {
	ifstream fileRes(fileNameRes);
	ifstream fileRoom(fileNameRoom);

	string datum;
	int mist;
zpet:
    system("cls");
    cout << "seznam mistnosti:" << endl;
	FreeRoom(fileNameRoom, x);
setDate:bool no = true;
	bool noRoom = true;
	cout << "Zadejte cislo mistnosti a datum" << endl;
	cin >> mist >> datum;
	if (ValidDate(datum)){
		for (int i = 0; i<count(fileNameRoom); i++) {
			if (x[i].numOfRoom == mist && x[i].freeCapacity != 0) {
				for (int j = 0; j<count(fileNameRes); j++) {
					if (x[i].ID == y[j].ID && y[j].date == datum) {
						cout << "mistnost je obsazena. " << endl;
                        cout << "Chcete zpet do [M]enu? nebo zmenit datum ci mistnost? Zmacknete y ." << endl;
						no = false;
						noRoom= true;
						char m;
						cin >> m;
						if (m == 'M' || m == 'm') {
							exit;

						}
						else if (m == 'Y' || m == 'y') {
							goto setDate;
						}
					}
				}
				if (no) {
					cout << "Mistnost je volna prejete si rezervaci? y/n " << endl;
					char v;
					cin >> v;
					if (v == 'y' || v == 'Y') {
						ofstream Res(fileNameRes, ios::app);
						Res << x[i].ID << "," << datum << endl;
						Res.close();
						system("cls");
						cout << "Vase rezervace se zapsala do souboru" << endl;
						noRoom=true;
                        exit;
					}
					else {
                            noRoom=true;
						exit;

					}
				}
				noRoom== true;
			}
			else if(x[i].numOfRoom != mist) noRoom = false;
		}
		if (noRoom == false) {
			cout << "Mistnost nenalezena chcete zmenit mistnost a datum? y/n" << endl;
			char d;
			cin >> d;
			if (d == 'Y' || d == 'y') {
				cin.clear();
				cin.ignore();
				goto zpet;
			}
			else {
                cout << "budete presmerovani do Menu" << endl;
                exit;
			}
       }
	}else {
        cout << "Spatne zadane datum, bude te presmerovani zpet k zadani data." << endl;
        cin.clear();
        cin.ignore();
        goto setDate;
       }
  fileRes.close();
  fileRoom.close();

}
void ExportToHtml(string fileNameRoom, string fileNameRes, rooms *x, reservation *y) {
	 system("cls");
	string header("<!DOCTYPE HTML PUBLIC \" -//W3C//DTD HTML 4.0 Transitional//EN\"><html><head><meta http - equiv = \"Content-Type\" content = \"text/html; charset=utf-8\"><title>Rezervace</title></head>");
	string body("<body><table width=\"500px\" border= \"1\"> <tr><td>ID mistnosti: </td><td>cislo mistnosti:</td><td> patro: </td> <td>cena: </td><td>datum rezervace:</td></tr>");
	string end("</table></body></html>");


time_t rawtime=time(0);
    struct tm * timeinfo;
    time(&rawtime);

    timeinfo = localtime(&rawtime);

    int currentyear = timeinfo -> tm_year + 1900;
    int currentmonth = timeinfo -> tm_mon + 1;
    int currentday = timeinfo -> tm_mday;

	ofstream output("vystupnidata/index.html");

	cout << " Vypis mistnosti: " << endl;
	FreeRoom(fileNameRoom, x);
	int idecko;
	bool nic = true;
	cout << "Zadejte mistnost jakou chcete exportovat do html." << endl;
	cin >> idecko;
	if (output.is_open())
	{
		output << header << body;
		output << "<h1>Prehled rezervaci na 30 dnu dane mistnosti: " << idecko << " od: " << currentday << "/" << currentmonth << "/" << currentyear << "</h1>" << endl;
		for (int i = currentday; i < currentday + 30; i++)
		{
			stringstream date;
			date << i << "/" << currentmonth << "/" << currentyear;
			for (int j = 0; j < count(fileNameRes); j++)
			{
				if (y[j].date == date.str())
				{
					for (int k = 0; k < count(fileNameRoom); k++)
					{
						if (y[j].ID == x[k].ID && x[k].numOfRoom == idecko)
						{
							output << "<tr><td>" << y[j].ID << "</td><td>" << x[k].numOfRoom << "</td><td>" << x[k].floor << "</td><td>" << x[k].prizePerDay << "</td><td>" << y[j].date << "</td></tr>";

						}
						else
						{
							nic = true;
						}
					}
				}
			}
		}
		if (nic) {
			output << "<td colspan = \"5\"> Zadne dalsi rezervace dane mistnosti. </td>";
		}
		output << end;
		output.close();
		cout << "Soubor byl uspesne vytvoren, budete presmerovan do hlavni nabidky" << endl;
		system("pause");

	}
	else {
		cout << "Nastala chyba, budete presmerovan do hlavni nabidky" << endl;
      exit;
	}
}
bool testInput(int cislo) {
	if (cin.fail()) {
		cout << "Nezadal jste cislo!, program bude ukoncen." << endl;
	}
	return true;
}
bool testCena(int cena) {
	if (cin.fail()) {
		cout << "Nezadal jste cenu, ale slovo nebo pismeno, program bude ukoncen." << endl;
	}
	return true;
}

