//#include "stdafx.h"
#include "Lista.h"
#include <random>
#include <fstream>
#include <iostream>

using namespace std;

Lista::Lista()
{
	rozmiar = 0;
	poczatek = nullptr;
	koniec = nullptr;
}

Lista::~Lista()
{
	poczatek = nullptr;
	koniec = nullptr;
	rozmiar = 0;
}

Element * Lista::getHead()
{
	return poczatek;
}

void Lista::StworzL(int val)
{
	poczatek = new Element;
	poczatek->wartosc = val;

	poczatek->nastepny = nullptr;
	poczatek->ostatni = nullptr;

	koniec = poczatek;

	rozmiar++;
}

int Lista::dodajWlos(int val, int indeks)
{
	int a;
	a = rozmiar + 1;
	if (indeks > 0 & indeks < a)
	{
		if (poczatek == nullptr) //jesli lista pusta
		{
			StworzL(val);
			dodajWpocz(val);
			return 0;
		}
		else
		{
			int index = indeks - 1;

			if (index == 0) //przejdz do dodaj na poczatku
			{
				dodajWpocz(val);
				return 0;
			}

			if (index == rozmiar) //przejdz do dodaj na koncu
			{
				dodajWkon(val);
				return index;
			}

			Element* newElement = new Element;
			newElement->wartosc = val;

			Element* temp = znajdzL(index);

			newElement->nastepny = temp;
			newElement->ostatni = temp->ostatni;

			temp->ostatni = newElement;
			newElement->ostatni->nastepny = newElement;

			rozmiar++;

			return index;
		}
	}
	else
	{
		system("cls");
		cout << endl << "Index spoza przedzialu sprobuj ponownie " << endl;
		Sleep(2000);
		system("cls");
	}
}

void Lista::dodajWpocz(int val)
{
	if (poczatek == nullptr) //jesli lista pusta
		StworzL(val);
	else
	{
		poczatek->ostatni = new Element;
		poczatek->ostatni->wartosc = val;
		poczatek->ostatni->nastepny = poczatek;
		poczatek->ostatni->ostatni = nullptr;
		if (rozmiar == 1)
			koniec = poczatek;
		poczatek = poczatek->ostatni;
		rozmiar++;
	}
}

void Lista::dodajWkon(int val)
{
	if (poczatek == nullptr) //jesli lista pusta
		StworzL(val);
	else
	{
		koniec->nastepny = new Element;
		koniec->nastepny->wartosc = val;
		koniec->nastepny->ostatni = koniec;
		koniec->nastepny->nastepny = nullptr;
		if (rozmiar == 1)
			poczatek = koniec;
		koniec = koniec->nastepny;
		rozmiar++;
	}
}

int Lista::usunWlos(int indeks){
	int pom = rozmiar;
	if (indeks > 0 & indeks < pom+1)
	{
		if (rozmiar > 0)
		{
			if (indeks > 0 || indeks < (pom -2)) {
				int index = indeks - 1;

				if (index == 0) //przejdz do usun na poczatku
				{
					usunWpocz();
					return 0;
				}

				if (index == pom) //przejdz do usun na koncu
				{
					usunWkon();
					return index;
				}

				Element* temp = znajdzL(index);

				temp->ostatni->nastepny = temp->nastepny;
				temp->nastepny->ostatni = temp->ostatni;
				delete temp;
				rozmiar--;

				return index;
			}
			else
			{
				system("cls");
				cout << endl << "Index spoza przedzialu sprobuj ponownie " << endl;
				Sleep(2000);
				system("cls");
			}
		}
	}
	else
	{
		system("cls");
		cout << endl << "Index spoza przedzialu sprobuj ponownie " << endl;
		Sleep(2000);
		system("cls");
	}
}
void Lista::usunWpocz()
{
	if (rozmiar)
	{
		if (rozmiar == 1)
			clear();
		else
		{
			poczatek = poczatek->nastepny;
			delete poczatek->ostatni;
			poczatek->ostatni = nullptr;
			rozmiar--;
		}
	}
}

void Lista::usunWkon()
{
	if (rozmiar)
	{
		if (rozmiar == 1)
			clear();
		else
		{
			koniec = koniec->ostatni;
			delete koniec->nastepny;
			koniec->nastepny = nullptr;
			rozmiar--;
		}
	}
}

Element * Lista::znajdzL(int index)
{
	Element* temp;

	if (index < rozmiar / 2)
	{
		temp = poczatek; //liczenie od head do przodu

		for (int i = 0; i < index; i++)
			temp = temp->nastepny;
	}
	else
	{
		temp = koniec; //liczenie od tail w tyl

		for (int i = rozmiar - 1; i > index; i--)
			temp = temp->ostatni;
	}
	return temp;
}

int Lista::znajdzWart(int val)
{
	Element* element = poczatek; //wskaznik na aktualny element

	for (int i = 0; i < rozmiar; i++)
	{
		if (element->wartosc == val)
			return	true;
		else
			element = element->nastepny;
	}
	return false;
}

bool Lista::zaladujzplikuLista()
{
	std::fstream file;
	int read; //liczby zczytane z pliku
	int readSize; //ilosc elementow zczytana z pliku

	file.open("Liczby.txt");

	if (file.is_open())
	{
		file >> readSize;

		if (file.fail())
			return false;
		else
		{
			for (int i = 0; i < readSize; i++)
			{
				file >> read;
				if (file.fail())
					return false;
				else
					dodajWkon(read);
			}
		}
		file.close();
		return true;
	}
	else
		return false;
}


void Lista::wyswietlListe()
{
	Element* element = poczatek; //wskaznik na aktualnie wypisywany element
	int columnCounter = 0; //licznik kolumn
	system("cls");

	for (int i = 0; i < rozmiar; i++)
	{

		cout << i + 1 << ". " << element->wartosc << endl;
		element = element->nastepny;
		if (++columnCounter == 20)
		{
			cout << endl;
			columnCounter = 0;
		}
	}
}

void Lista::clear()
{
	poczatek = nullptr;
	koniec = nullptr;
	rozmiar = 0;
}
void Lista::czyJest(int value)
{
	if (znajdzWart(value) == true)
	{
		system("cls");
		cout << endl << "Wartosc- " << value << ", znajduje sie w liscie" << endl;
		Sleep(2000);
		system("cls");
	}
	else
	{
		system("cls");
		cout << endl << "Wartosc- " << value << ", nie znajduje sie w liscie" << endl;
		Sleep(2000);
		system("cls");
	}
}