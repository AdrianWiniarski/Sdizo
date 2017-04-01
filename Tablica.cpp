#include "stdafx.h"
#include "Tablica.h"
#include <iostream>

using namespace std;


void Tablica::dodajliczbenak()
{
	rozmiar++;
	int *Kopia = new int[rozmiar]; // tworze kopie tablicy liczb
	
	for (int i = 0; i < rozmiar-1; i++) // nadpisuje kazdy element biorac obiekty z kopii (referencyjnie)
	{
		Kopia[i] = Tab[i];
	}
	delete[] Tab; // usuwam z pamieci
	int a;
	a = rand();
	Kopia[rozmiar-1] = a;
	Tab = Kopia;
};

void Tablica::dodajliczbenap()
{

	rozmiar++;
	int *Kopia = new int[rozmiar]; // tworze kopie tablicy liczb

	for (int i = 0; i < rozmiar - 1; i++) // nadpisuje kazdy element biorac obiekty z kopii (referencyjnie)
	{
		Kopia[i+1] = Tab[i];
	}
	delete[] Tab; // usuwam z pamieci
	int a;
	a = rand();
	Kopia[0] = a;
	Tab = Kopia;
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
	int a;
	if (rozmiar > 0)
	{
		rozmiar++;
		do {
			cout << endl << "Podaj miejsce z przedziału <" << 1 << "," << rozmiar << "> w którym ma być dodana liczba " << endl;
			cin >> a;
		} while (a<0 || a>rozmiar);
		
		int *Kopia = new int[rozmiar]; // tworze kopie tablicy liczb
		
		for (int i = 0; i < a-1; i++) // nadpisuje kazdy element biorac obiekty z kopii (referencyjnie)
		{
			Kopia[i] = Tab[i];
		}
		for (int i = a-1 ; i < rozmiar; i++)
		{
			Kopia[i] = Tab[i];
		}
		Kopia[a] = rand();
		delete[] Tab; // usuwam z pamieci
		Tab = Kopia;
	}
	else
	{
		rozmiar++;
		int *Kopia = new int[rozmiar]; // tworze kopie tablicy liczb

		for (int i = 0; i < rozmiar - 1; i++) // nadpisuje kazdy element biorac obiekty z kopii (referencyjnie)
		{
			Kopia[i] = Tab[i];
		}
		delete[] Tab; // usuwam z pamieci
		a = rand();
		Kopia[rozmiar - 1] = a;
		Tab = Kopia;
	}
};

void Tablica::wypisztablice()
{
	system("cls");
	for (int i = 0; i < rozmiar; i++)
	{
		cout<<endl<<i+1<<". "<< Tab[i];
	}
	cout << endl;
};

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
