//#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <conio.h>
#include <string>
#include <fstream>
#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"
#include <windows.h>


using namespace std;

LARGE_INTEGER startTimer()
{
	LARGE_INTEGER start;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&start);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return start;
}

LARGE_INTEGER endTimer()
{
	LARGE_INTEGER stop;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&stop);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return stop;
}



void displayMenu(string info)
{

	cout << endl;
	cout << info << endl;
	cout << "1.zaladuj Tablice" << endl;
	cout << "2.Usun na poczatku" << endl;
	cout << "3.Usun na koncu" << endl;
	cout << "4.Dodaj na poczatku" << endl;
	cout << "5.Dodaj na koncu" << endl;
	cout << "6.Dodaj losowo" << endl;
	cout << "7.Usun losowo" << endl;
	cout << "8.Wyswietl" << endl;
	cout << "9.Znajdz" << endl;
	cout << "t.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

void displayMenu1(string info)
{

	cout << endl;
	cout << info << endl;
	cout << "1.zaladuj z pliku" << endl;
	cout << "2.Usun z listy na poczatku" << endl;;
	cout << "3.Dodaj do listy na poczatku" << endl;
	cout << "4.Usun z listy na koncu" << endl;;
	cout << "5.Dodaj do listy na koncu" << endl;
	cout << "6.Usun z listy losowo" << endl;;
	cout << "7.Dodaj do listy losowo" << endl;
	cout << "8.znajdz" << endl;
	cout << "9.Wyswietl" << endl;
	cout << "t.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

//Table myTab; //myTab mo¿e byæ dynamiczna, mo¿e byc zadeklarowana w manu_table 
void displayMenu2(string info)
{

	cout << endl;
	cout << info << endl;
	cout << "1.Dodaj do kopca" << endl;
	cout << "2.Usun z kopca" << endl;;
	cout << "3.znajdz" << endl;
	cout << "4.wyswiatl" << endl;
	cout << "5.zaladuj" << endl;
	cout << "t.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

void menu_tablicy()
{
	char opt1, opt2;
	int index, value, x;
	Tablica myTab;

	do {
		displayMenu("--- TABLICA ---");
		opt1 = _getch();
		cout << endl;
		switch (opt1) {
		case '1': //Tworzenie tablicy
			myTab.zaladujzpliku();
			myTab.wypisztablice();
			break;

		case '2': //Usuwanie elementu z tablicy na poczatku
			myTab.usunliczbenap();
			myTab.wypisztablice();
			break;

		case '3': //usuwanie elemetu do tablicy na koncu
			myTab.usunliczbenak();
			myTab.wypisztablice();
			break;

		case '4': //dodawanie liczby na poczatku

			cout << " podaj liczbe jaka chcesz dodac " << endl;
			cin >> x;
			myTab.dodajliczbenap(x);
			myTab.wypisztablice();
			break;
		case '5':  //dodaj liczbe na koncu

			cout << " podaj liczbe jaka chcesz dodac " << endl;
			cin >> x;
			myTab.dodajliczbenak(x);
			myTab.wypisztablice();
			break;

		case '6': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie bêdzie testowana przez prowadz¹cego 

			cout << " podaj liczbe jaka chcesz dodac " << endl;
			cin >> x;
			cout << " podaj index " << endl;
			cin >> index;
			myTab.dodajliczbelos(x, index);
			myTab.wypisztablice();
			break;
		case '7':
			cout << endl << "Podaj index do usuniecia :" << endl;
			cin >> index;
			myTab.usunliczbelos(index);
			myTab.wypisztablice();
			break;
		case '8': //wyswietla tablice
			myTab.wypisztablice();
			break;
		case '9':
			cout << "Podaj liczbe jaka chces znalezc w tablicy " << endl;
			cin >> value;
			myTab.szukaj(value);
			break;
		case 't':

			do {

				displayMenu("--- POMIAR CZASU ---");
				opt2 = _getch();
				cout << endl;
				LARGE_INTEGER performanceCountStart, performanceCountEnd;
				performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
				switch (opt2) {

				case '1': // Wczytywanie tablicy z pliku
				{
					myTab.zaladujzpliku(); //tutaj funkcje, których mierzymy wydajnoœæ
					break;
				}
				case '2': //Usuwanie elementu z tablicy na poczatku
					myTab.usunliczbenap();
					myTab.wypisztablice();
					break;

				case '3': //usuwanie elemetu do tablicy na koncu
					myTab.usunliczbenak();
					myTab.wypisztablice();
					break;

				case '4': //dodawanie liczby na poczatku

					cout << " podaj liczbe jaka chcesz dodac " << endl;
					cin >> x;
					myTab.dodajliczbenap(x);
					myTab.wypisztablice();
					break;
				case '5':  //dodaj liczbe na koncu

					cout << " podaj liczbe jaka chcesz dodac " << endl;
					cin >> x;
					myTab.dodajliczbenak(x);
					myTab.wypisztablice();
					break;

				case '6': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie bêdzie testowana przez prowadz¹cego 

					cout << " podaj liczbe jaka chcesz dodac " << endl;
					cin >> x;
					cout << " podaj index " << endl;
					cin >> index;
					myTab.dodajliczbelos(x, index);
					myTab.wypisztablice();
					break;
				case '7':
					cout << endl << "Podaj index do usuniecia :" << endl;
					cin >> index;
					myTab.usunliczbelos(index);
					myTab.wypisztablice();
					break;
				case '8': //wyswietla tablice
					myTab.wypisztablice();
					break;
				case '9':
					cout << "Podaj liczbe jaka chces znalezc w tablicy " << endl;
					cin >> value;
					myTab.szukaj(value);
					break;



				}
				performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
				double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
				cout << endl << "Time:" << tm << endl;

			} while (opt2 != '0');
		}

	} while (opt1 != '0');

}

void menu_listy()
{
	char opt1, opt2;
	int index, value;
	Lista myList;


	do {
		displayMenu1("--- LISTA ---");
		opt1 = _getch();
		cout << endl;
		switch (opt1) {
		case '1': // Wczytywanie listy z pliku
			myList.zaladujzplikuLista();
			myList.wyswietlListe();
			break;

		case '2': //Usuwanie elementu z listy
			myList.usunWpocz();
			myList.wyswietlListe();
			break;

		case '3': //Dodawanie elementu do listy
			cout << " Podaj wartosc:";
			cin >> value;
			myList.dodajWpocz(value);
			myList.wyswietlListe();
			break;

		case '4': //Znajdowanie elementu w liscie
			myList.usunWkon();
			myList.wyswietlListe();
			break;
		case '5':  //Wyswietlanie listy
			cout << " Podaj wartosc:";
			cin >> value;
			myList.dodajWkon(value);
			myList.wyswietlListe();
			break;
		case '6':  //Wyswietlanie listy
			cout << "Podaj indeks: ";
			cin >> index;
			myList.usunWlos(index);
			myList.wyswietlListe();
			break;
		case '7':  //Wyswietlanie listy
			cout << "Podaj indeks: ";
			cin >> index;
			cout << " Podaj wartosc:";
			cin >> value;
			myList.dodajWlos(value, index);
			myList.wyswietlListe();
			break;
		case '8':  //Wyswietlanie listy
			cout << "Podaj szukana wartosc :" << endl;
			cin >> value;
			myList.czyJest(value);
			myList.wyswietlListe();
			break;
		case '9':  //Wyswietlanie listy
			myList.wyswietlListe();
			break;
		case't':
			do {

				displayMenu1("--- POMIAR CZASU ---");
				opt2 = _getch();
				cout << endl;
				LARGE_INTEGER performanceCountStart, performanceCountEnd;
				performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
				switch (opt2) {

				case '1': // Wczytywanie listy z pliku
					myList.zaladujzplikuLista();
					myList.wyswietlListe();
					break;

				case '2': //Usuwanie elementu z listy
					myList.usunWpocz();
					myList.wyswietlListe();
					break;

				case '3': //Dodawanie elementu do listy
					cout << " Podaj wartosc:";
					cin >> value;
					myList.dodajWpocz(value);
					myList.wyswietlListe();
					break;

				case '4': //Znajdowanie elementu w liscie
					myList.usunWkon();
					myList.wyswietlListe();
					break;
				case '5':  //Wyswietlanie listy
					cout << " Podaj wartosc:";
					cin >> value;
					myList.dodajWkon(value);
					myList.wyswietlListe();
					break;
				case '6':  //Wyswietlanie listy
					cout << "Podaj indeks: ";
					cin >> index;
					myList.usunWlos(index);
					myList.wyswietlListe();
					break;
				case '7':  //Wyswietlanie listy
					cout << "Podaj indeks: ";
					cin >> index;
					cout << " Podaj wartosc:";
					cin >> value;
					myList.dodajWlos(value, index);
					myList.wyswietlListe();
					break;
				case '8':  //Wyswietlanie listy
					cout << "Podaj szukana wartosc :" << endl;
					cin >> value;
					myList.czyJest(value);
					myList.wyswietlListe();
					break;
				case '9':  //Wyswietlanie listy
					myList.wyswietlListe();
					break;



				}
				performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
				double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
				cout << endl << "Time:" << tm << endl;

			} while (opt2 != '0');




		}

	} while (opt1 != '0');
}

void menu_kopca()
{
	int index, liczba;
	char opt1, opt2;
	Kopiec myHeap;

	do {
		displayMenu2("--- KOPIEC ---");
		opt1 = _getch();
		cout << endl;
		switch (opt1) {
		case '1': //dodaj kpiec
			cout << " Podaj wartosc:";
			cin >> index;
			myHeap.dodaj(index);
			myHeap.wyswietlKopiec(" ", " ", 0);
			break;

		case '2': //Usuwanie elementu z kopca
			cout << " Podaj wartosc:";
			cin >> liczba;
			myHeap.usun(liczba);
			myHeap.wyswietlKopiec(" ", " ", 0);
			break;
		case'3'://znajdowanie elem w kopcu
			cout << "Podaj wartosc:";
			cin >> liczba;
			if (myHeap.sprawdzCzyIstnieje(liczba))
				cout << "Podana wartosc jest na liscie";
			else
				cout << "Podanej wartosci NIE ma na liscie";
			break;

		case '4': //wyswietl kopiec 
			myHeap.wyswietlKopiec(" ", " ", 0);
			break;

		case '5': //zaladuj
			myHeap.zaladujzpliku();
			myHeap.wyswietlKopiec(" ", " ", 0);
			break;
		case 't':  //TEST
			do {

				displayMenu2("--- POMIAR CZASU ---");
				opt2 = _getch();
				cout << endl;
				LARGE_INTEGER performanceCountStart, performanceCountEnd;
				performanceCountStart = startTimer(); //zapamiêtujemy czas pocz¹tkowy
				switch (opt2) {

				case '1': //dodaj kpiec
					cout << " Podaj wartosc:";
					cin >> index;
					myHeap.dodaj(index);
					myHeap.wyswietlKopiec(" ", " ", 0);
					break;

				case '2': //Usuwanie elementu z kopca
					cout << " Podaj wartosc:";
					cin >> liczba;
					myHeap.usun(liczba);
					myHeap.wyswietlKopiec(" ", " ", 0);
					break;
				case'3'://znajdowanie elem w kopcu
					cout << "Podaj wartosc:";
					cin >> liczba;
					if (myHeap.sprawdzCzyIstnieje(liczba))
						cout << "Podana wartosc jest na liscie";
					else
						cout << "Podanej wartosci NIE ma na liscie";
					break;

				case '4': //wyswietl kopiec
					myHeap.wyswietlKopiec(" ", " ", 0);
					break;

				case '5': //zaladuj
					myHeap.zaladujzpliku();
					break;

				}
				performanceCountEnd = endTimer(); //zapamiêtujemy koniec czasu
				double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
				cout << endl << "Time:" << tm << endl;

			} while (opt2 != '0');
			break;

		}

	} while (opt1 != '0');
}

int main(int argc, char* argv[])
{
	srand(time(NULL));

	char option;
	do {
		cout << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.Tablica" << endl;
		cout << "2.Lista" << endl;
		cout << "3.Kopiec" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje:";
		option = _getch();
		cout << endl;

		switch (option) {
		case '1':
			menu_tablicy();
			break;

		case '2':
			menu_listy();
			break;

		case '3':
			menu_kopca();
			break;
		}

	} while (option != '0');


	return 0;
}