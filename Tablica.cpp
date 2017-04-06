#include "stdafx.h"
#include "Tablica.h"
#include <iostream>

using namespace std;


void Tablica::dodajliczbenak()
{
	rozmiar++;
	int *Kopia = new int[rozmiar]; // tworze kopie tablicy liczb

	for (int i = 0; i < rozmiar - 1; i++) // nadpisuje kazdy element biorac obiekty z kopii (referencyjnie)
	{
		Kopia[i] = Tab[i];
	}
	delete[] Tab; // usuwam z pamieci
	int a;
	a = rand();
	Kopia[rozmiar - 1] = a;
	Tab = Kopia;
	Kopia = nullptr;
};

void Tablica::dodajliczbenap()
{

	rozmiar++;
	int *Kopia = new int[rozmiar]; // tworze kopie tablicy liczb

	for (int i = 0; i < rozmiar - 1; i++) // nadpisuje kazdy element biorac obiekty z kopii (referencyjnie)
	{
		Kopia[i + 1] = Tab[i];
	}
	delete[] Tab; // usuwam z pamieci
	int a;
	a = rand();
	Kopia[0] = a;
	Tab = Kopia;
	Kopia = nullptr;
};

void Tablica::usunliczbenap()
{
	if (rozmiar > 0)
	{
		rozmiar--;
		int *Kopia = new int[rozmiar]; // tworze kopie tablicy liczb

		for (int i = 0; i < rozmiar; i++) // nadpisuje kazdy element biorac obiekty z kopii (referencyjnie)
		{
			Kopia[i] = Tab[i + 1];
		}
		delete[] Tab; // usuwam z pamieci
		Tab = Kopia;
		Kopia = nullptr;
	}
	else
	{
		cout << endl << "Wielkosc tablicy jest rowna: " << rozmiar << "." << endl << "Zalecane: Stworz tablice." << endl;
		getch();
	}
};

void Tablica::usunliczbenak()
{

	if (rozmiar > 0)
	{
		rozmiar--;
		int *Kopia = new int[rozmiar]; // tworze kopie tablicy liczb

		for (int i = 0; i < rozmiar; i++) // nadpisuje kazdy element biorac obiekty z kopii (referencyjnie)
		{
			Kopia[i] = Tab[i];
		}
		delete[] Tab; // usuwam z pamieci
		Tab = Kopia;
		Kopia = nullptr;
	}
	else
	{
		system("cls");
		cout << endl << "Wielkosc tablicy jest rowna: " << rozmiar << "." << endl << "Zalecane: Stworz tablice." << endl;
		Sleep(3000);
		system("cls");
	}

};

void Tablica::usunliczbelos()
{
	if (rozmiar != 0) {
		int indeks;
		if (rozmiar == 0)   indeks = 0;         //unikamy dzielenia przez zero
		else indeks = rand() % rozmiar;

		int *Kopia = new int[rozmiar - 1];
		for (int i = 0; i < indeks; i++) {
			Kopia[i] = Tab[i];                //przepisz wszystkie wartosci przed indeksem usuwanej wartosci
		}
		for (int i = 0; i < (rozmiar - 1); i++) {
			Kopia[i] = Tab[i + 1];
		}

		delete[] Tab;
		Tab = Kopia;
		Kopia = nullptr;
		rozmiar--;
	}
	else
	{
		system("cls");
		cout << endl << "Wielkosc tablicy jest rowna: " << rozmiar << "." << endl << "Zalecane: Stworz tablice." << endl;
		Sleep(3000);
		system("cls");
	}
};

void Tablica::dodajliczbelos()
{
	//wybrane if (indeks >= rozmiar || indeks<0)    return false;       //sprawdz czy ktos nie podal za duzego indeksu
	//wybrane else {
	int liczba;
	liczba = rand();
	int indeks;
	if (rozmiar == 0)   indeks = 0;         //unikamy dzielenia przez zero
	else indeks = rand() % rozmiar;


	int *Kopia = new int[rozmiar + 1];    //wskaznik na nowa o jeden wieksza tablcie
	Kopia[indeks] = liczba;               //wstaw zadana liczbe na zadane miejsce

	for (int i = 0; i < indeks; i++) {      //do miejsca wstawienia nowej wartosci
		Kopia[i] = Tab[i];                //przepisz stare
	}
	for (int i = indeks; i < rozmiar; i++) {//kolejne tez przepisz
		Kopia[i + 1] = Tab[i];
	}

	delete[] Tab;               //zwolnij pamiec
	Tab = Kopia;          //przypisz nowy wskaznik
	Kopia = nullptr;
	rozmiar++;              //zwieksz rozmiar o jeden
    //return indeks;
	//wybrane }
};

void Tablica::wypisztablice()
{
	system("cls");
	for (int i = 0; i < rozmiar; i++)
	{
		cout << endl << i + 1 << ". " << Tab[i];
	}
	cout << endl;
}
void Tablica::zaladujzpliku()
{

	fstream plik;
	plik.open("liczby.txt");
	plik >> rozmiar;
	Tab = new int[rozmiar];
	if (plik.good() == false)
		cout << "Plik zostal zle wczytany";
	for (int i = 0; i<rozmiar; i++)
		plik >> Tab[i];
	plik.close();
}
;

Tablica::Tablica()
{
	rozmiar = 0;//zeruje parametry
	Tab = NULL;
};


Tablica::~Tablica()
{

	rozmiar = 0;
	delete[] Tab;
	Tab = 0;
};

void Tablica::Stworz()
{
	Tab = NULL;
	cout << endl << "Podaj ilosc elementow tablicy jaka chcesz stworzyc: " << endl;
	cin >> rozmiar;
	system("cls");
	cout << "Podana ilosc wynosi " << rozmiar;
	Sleep(2000);
	system("cls");
	cout << "Trwa tworzenie tablicy " << endl;
	Sleep(2000);
	Tab = new int[rozmiar];
	for (int i = 0; i<rozmiar; i++)
	{
		Tab[i] = rand();
	}
};
