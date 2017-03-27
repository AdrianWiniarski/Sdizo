#include "stdafx.h"
#include "Tablica.h"
#include <iostream>

using namespace std;


void Tablica::dodajliczbenak()
{

	Tablica *Kopia = new Tablica; // tworze kopie tablicy liczb
	delete[] Tab; // usuwam z pamieci
	Tab = nullptr;
	rozmiar++;
	Tab = new int[rozmiar]; // alokuje nowa o 1 wieksza
	for (int i = 0; i < licznik; i++) // nadpisuje kazdy element biorac obiekty z kopii (referencyjnie)
	{
		Tab[i] = Kopia->Tab[i];
	}
};

void Tablica::dodajliczbenap()
{


	Tablica *Kopia = new Tablica; // tworze kopie tablicy liczb
	delete[] Tab; // usuwam z pamieci
	Tab = nullptr;
	rozmiar++;
	Tab = new int[rozmiar]; // alokuje nowa o 1 mniejsza
	for (int i = 1; i < licznik; i++) // nadpisuje kazdy element biorac obiekty z kopii (referencyjnie)
	{
		Tab[i] = Kopia->Tab[i];
	}
	int a;
	cout << endl << "Podaj liczbe ktora chcesz dodac na poczatek :" << endl;
	cin >> a;

	Tab[0] =a; 
};

void Tablica::usunliczbenap()
{
	Tablica *Kopia = new Tablica; // tworze kopie tablicy liczb
	delete[] Tab; // usuwam z pamieci
	Tab = nullptr;
	rozmiar--;
	Tab = new int[rozmiar]; // alokuje nowa o 1 mniejsza
	for (int i = 1; i < licznik; i++) // nadpisuje kazdy element biorac obiekty z kopii (referencyjnie)
	{
		Tab[i] = Kopia->Tab[i];
	}
};

void Tablica::usunliczbenak()
{

	Tablica *Kopia = new Tablica; // tworze kopie tablicy liczb
	delete[] Tab; // usuwam z pamieci
	Tab = nullptr;
	rozmiar--;
	Tab = new int[rozmiar]; // alokuje nowa o 1 mniejsza
	for (int i = 0; i < licznik; i++) // nadpisuje kazdy element biorac obiekty z kopii (referencyjnie)
	{
		Tab[i] = Kopia->Tab[i];
	}

};

/*void Tablica::dodajliczbelos()
{

	Tablica Kopia(*this); // tworze kopie tablicy liczb
	delete[] Tab; // usuwam z pamieci
	rozmiar++;
	Tab = new Liczba[rozmiar]; // alokuje nowa o 1 mniejsza
	for (int i = 0; i < licznik; i++) // nadpisuje kazdy element biorac obiekty z kopii (referencyjnie)
	{
		Tab[i] = Kopia.Tab[i++];
	}

};*/

void Tablica::wypisztablice()
{
	for (int i = 0; i < licznik; i++)
	{
		cout << Tab[i] << " ";
	}
};

Tablica::Tablica()
{
	rozmiar = 0;//zeruje parametry
	Tab = NULL;
	licznik = 0;
};


Tablica::~Tablica()
{
	licznik = 0;
	rozmiar = 0;
	delete[] Tab;
	Tab = 0;
};
