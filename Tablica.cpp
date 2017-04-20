#include "stdafx.h"
#include "Tablica.h"
#include <iostream>

using namespace std;


void Tablica::dodajliczbenak(int liczba)
{
	rozmiar++;
	int *Kopia = new int[rozmiar]; // tworze kopie tablicy liczb

	for (int i = 0; i < rozmiar - 1; i++) // nadpisuje kazdy element biorac obiekty z kopii (referencyjnie)
	{
		Kopia[i] = Tab[i];
	}
	delete[] Tab; // usuwam z pamieci
	int a;
	a = liczba;
	Kopia[rozmiar - 1] = a;
	Tab = Kopia;
	Kopia = nullptr;
};

void Tablica::dodajliczbenap(int liczba)
{

	rozmiar++;
	int *Kopia = new int[rozmiar]; // tworze kopie tablicy liczb

	for (int i = 0; i < rozmiar - 1; i++) // nadpisuje kazdy element biorac obiekty z kopii (referencyjnie)
	{
		Kopia[i + 1] = Tab[i];
	}
	delete[] Tab; // usuwam z pamieci
	int a;
	a = liczba;
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

void Tablica::szukaj(int val)
{
	int x=0;
	for (int i = 0; i < rozmiar; i++)
	{
		if(Tab[i]==val)
		{
			x = 1;
		}
	};
	if (x == 1)
	{
		system("cls");
		cout << "W tablicy znajduje sie liczba " << val << endl;
		Sleep(2000);
		system("cls");
	}
	else
	{
		system("cls");
		cout << "W tablicy nie ma liczby " << val << endl;
		Sleep(2000);
		system("cls");
	}
};

void Tablica::usunliczbelos(int index)
{

	//Sprawdź, czy tablica nie jest pusta
	//Sprawdż czy pozycja nie wykracza poza tablicę
	if (rozmiar) {
		if (index > 0 & index < rozmiar++)
		{
			if (rozmiar > 0)
			{
				if(index==rozmiar)
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
				else if (index > 0 || index < (rozmiar - 1))
				{
					index--;
					//Zaalokuj pamięć na tablicę mniejszą o jeden element niż poprzednio
					int *Kopia = new int[rozmiar - 1];

					//Przepisz elementy do wybranej pozycji
					for (int i = 0; i < index; i++) {
						Kopia[i] = Tab[i];
					}

					rozmiar--;

					//Przepisz elementy po wybranej pozycji
					for (int i = index++; i < rozmiar; i++) {
						Kopia[i] = Tab[i + 1];
					}

					delete[] Tab;
					Tab = Kopia;

					rozmiar--;
					int *Kopia1 = new int[rozmiar]; // tworze kopie tablicy liczb

					for (int i = 0; i < rozmiar; i++) // nadpisuje kazdy element biorac obiekty z kopii (referencyjnie)
					{
						Kopia1[i] = Tab[i];
					}
					delete[] Tab; // usuwam z pamieci
					Tab = Kopia1;
					Kopia1 = nullptr;
					
				}
			}
			else {
				system("cls");
				cout << "W tablicy nie istnieje pozycja " << index << endl;
				Sleep(2000);
				system("cls");
			}
		}

	}
};


void Tablica::dodajliczbelos(int liczba, int index)
{
	index = index - 1;
	if (index > rozmiar || index < 0)           //sprawdz czy ktos nie podal za duzego indeksu
	{
		system("cls");
		cout << "Liczba znajduje sie poza zakresem tablicy" << endl;
			Sleep(2000);
	}
	else {
	
	
	if (rozmiar == 0)   index = 0;         //unikamy dzielenia przez zero
	


	int *Kopia = new int[rozmiar + 1];    //wskaznik na nowa o jeden wieksza tablcie
	Kopia[index] = liczba;               //wstaw zadana liczbe na zadane miejsce

	for (int i = 0; i < index; i++) {      //do miejsca wstawienia nowej wartosci
		Kopia[i] = Tab[i];                //przepisz stare
	}
	for (int i = index; i < rozmiar; i++) {//kolejne tez przepisz
		Kopia[i + 1] = Tab[i];
	}

	delete[] Tab;               //zwolnij pamiec
	Tab = Kopia;          //przypisz nowy wskaznik
	Kopia = nullptr;
	rozmiar++;              //zwieksz rozmiar o jeden
  
	
	}
};

void Tablica::wypisztablice()
{
	if (rozmiar > 0)
	{
		system("cls");
		for (int i = 0; i < rozmiar; i++)
		{
			cout << endl << i + 1 << ". " << Tab[i];
		}
		cout << endl;
	}
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
