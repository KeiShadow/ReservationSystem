//! \file functions.h
//! \brief Hlavickovy soubor dokumentu s deklaracemi vsech funkci
//! \author Petr Noga
//! \version 2
//! \date 20. December 2015
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <time.h>
#include <cstdlib>


using namespace std;
//! \brief              Struktura rooms
//! \value ID           ID mistnosti
//! \value floor        Poschodi
//! \value numOfRoom    mistnosti
//! \value capacity     Pocet sedadel
//! \value prizePerDay  Cena za den
struct rooms {
	int ID;
	int floor;
	int numOfRoom;
	int freeCapacity;
	int capacity;
	int prizePerDay;
};

//! \brief              Struktura rooms
//! \value ID           ID
//! \value date         Datum
struct reservation {
	int ID;
	string date;
};
//! \brief              Funkce na otestovani spravne zadaneho data.
//! \param date         Chceme overit zadane datum
//! \return true        Spravne zadane datum
//! \return false       Spatne zadane datum
bool ValidDate(string date);

//! \brief              Funkce, ktera vraci pocet radku zadaneho souboru
//! \param fileName     Nazev souboru
//! \return i           Vraci pocet radku v souboru
int count(string fileName);

//! \brief              Funkce, ktera nacita informace mistnosti do struktury
//! \param fileName     Nazev souboru
//! \param rooms *x     strukturu rooms predavame do x
void ReadRoom(string fileName, rooms *x);

//! \brief              Funkce, ktera nacita informace rezervace do struktury
//! \param fileName     Nazev souboru
//! \param reservation *y     strukturu reservation predavame do y
void ReadRes(string fileName, reservation *y);

//! \brief              Funkce, ktera zobrazi vsechny mistnosti se stejnym id ze struktury i s datem
//! \param fileNameRoom     Nazev souboru room
//! \param fileNameRes      Nazev souboru res
//! \param rooms *x     dynamicke polse struktury ktere  prevadi polozky ze struktury rooms do x
//! \param reservation *y    dynamicke polse struktury ktere  prevadi polozky ze struktury reservation do y
void AllRoom(string fileNameRoom, string fileNameRes ,rooms *x, reservation *y);

//! \brief              Funkce, ktera zobrazi vsechny volne mistnosti se stejnym id ze struktury
//! \param fileNameRoom     Nazev souboru room
//! \param rooms *x     dynamicke polse struktury ktere  prevadi polozky ze struktury rooms do x
void FreeRoom(string fileNameRoom, rooms *x);

//! \brief                  Funkce, ktera zobrazi vsechny volne mistnosti se stejnym id ze struktury do zadane ceny
//! \param fileNameRoom     Nazev souboru room
//! \param rooms *x         dynamicke polse struktury ktere  prevadi polozky ze struktury rooms do x
//! \param cena             cena kterou zadame
void PrizeByFreeRoom(string fileNameRoom, int cena, rooms *x);

//! \brief                  Funkce, ktera zobrazi vsechny mistnosti se stejnym id ze struktury podle zadaneho data
//! \param fileNameRoom     Nazev souboru room
//! \param fileNameRes      Nazev souboru res
//! \param rooms *x         dynamicke polse struktury ktere  prevadi polozky ze struktury rooms do x
//! \param reservation *y   dynamicke polse struktury ktere  prevadi polozky ze struktury reservation do y
void DateByFreeRoom(string fileNameRoom, string fileNameRes, rooms *x, reservation *y);

//! \brief                  Funkce, ktera zapisuje zadane mistnosti rezervace do souboru
//! \param fileNameRoom     Nazev souboru room
//! \param fileNameRes      Nazev souboru res
//! \param rooms *x         dynamicke polse struktury ktere  prevadi polozky ze struktury rooms do x
//! \param reservation *y   dynamicke polse struktury ktere  prevadi polozky ze struktury reservation do y
void ResByDate(string fileNameRoom, string fileNameRes, rooms *x, reservation *y);

//! \brief                  Funkce, ktera exportuje rezervace do tabulky HTML souboru
//! \param fileNameRoom     Nazev souboru room
//! \param fileNameRes      Nazev souboru res
//! \param rooms *x         dynamicke polse struktury ktere  prevadi polozky ze struktury rooms do x
//! \param reservation *y   dynamicke polse struktury ktere  prevadi polozky ze struktury reservation do y
void ExportToHtml(string fileNameRoom, string fileNameRes, rooms *x, reservation *y);

//! \brief              Funkce na otestovani spravne zadaneho cisla v menu
//! \param cislo        Chceme overit zadane cislo zda neni slovo, nebo znak
//! \return true        Spravne zadane cislo
//! \return false       Spatne zadane cislo
bool testInput(int cislo);

//! \brief              Funkce na otestovani spravne zadanehe ceny
//! \param cena         Chceme overit zadanou cenu zdna neni slovo nebo, jiny znak
//! \return true        Spravne zadane cislo
//! \return false       Spatne zadane cislo
bool testCena(int cena);


#endif // FUNCTIONS_H_INCLUDED
