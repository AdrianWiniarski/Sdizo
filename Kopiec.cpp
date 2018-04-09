//#include "stdafx.h"
#include "Kopiec.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Kopiec::Kopiec() {
	Kopiec::Tab = nullptr;
	Kopiec::rozmiar = 0;

}

bool Kopiec::zaladujzpliku() {

	int n = 0;
	int j, k;
	int v;
	fstream plik;
	plik.open("liczby.txt");
	plik >> rozmiar;
	Tab = new int[rozmiar];
	if (plik.good() == false) {
		cout << "Plik zostal zle wczytany";
		return false;
	}
	for (int i = 0; i<rozmiar; i++) {
		j = n++;
		k = (j - 1) / 2;
		plik >> v;
		while (j>0 && Tab[k]<v) {
			Tab[j] = Tab[k];
			j = k;
			k = (j - 1) / 2;
		}
		Tab[j] = v;
	}
	plik.close();
	return true;
}

Kopiec::~Kopiec() {

	if (Kopiec::rozmiar > 0) {
		delete[]Tab;
	}

}

void Kopiec::dodaj(int wartosc) {


	if (!Kopiec::sprawdzCzyIstnieje(wartosc)) {
		int *Kopia = new int[rozmiar + 1];
		for (int i = 0; i < rozmiar; i++) {
			Kopia[i] = Tab[i];
		}
		Kopia[rozmiar] = wartosc;
		delete[]Tab;
		Tab = Kopia;
		Kopiec::poprawStrukture();
		rozmiar++;


	}

}

void Kopiec::usun(int wartosc) {


	for (int i = 0; i < rozmiar; i++) {

		if (Tab[i] == wartosc) {
			int *Kopia = new int[rozmiar - 1];

			for (int k = 0; k < i; k++) {
				Kopia[k] = Tab[k];
			}
			for (int k = i + 1; k < rozmiar; k++) {
				Kopia[k - 1] = Tab[k];
			}
			delete[]Tab;
			Tab = Kopia;

			rozmiar--;

			Kopiec::poprawStrukture();
			return;

		}

	}

}

bool Kopiec::sprawdzCzyIstnieje(int wartosc) {


	for (int i = 0; i < rozmiar; i++) {

		if (Tab[i] == wartosc) {
			system("cls");
			cout << "Szukana wartosc znajduje sie w kopcu" << endl;
			Sleep(2000);
			system("cls");
			return true;
		}
	}
	system("cls");
	cout << "Szukana wartosc nie znajduje sie w kopcu" << endl;
	Sleep(2000);
	system("cls");
	return false;

}



void Kopiec::wyswietlKopiec(string sp, string sn, int value) {// funkcja, ktora obrazuje budowe kopca i wyswietla na ekranie
	if (rozmiar == 0) // sprawdzanie warunku czy kopiec nie jest pusty
	{
		cout << "Kopiec jest pusty." << endl;

		return;
	}
	string s; // zmienna pomocnicza przy realizacji graficznej drzewa
	string cr, cl, cp; // inicjowanie zmiennych, ktora beda stanowily nasze polaczenie wizualne pomiedzy wezlami
	cr = cl = cp = "  "; // zmienne, ktore pozwalaja na wyswietlanie kopca w poprawny sposob
	cr[0] = 218; cr[1] = 196; cl[0] = 192; cl[1] = 196; cp[0] = 179; // nadanie wartosci zmiennym tak, aby odstep pomiedzy wezlami byl zachowany i struktura wygladala jak drzewo (wykorzystanie kodow tablicy kodow ASCII)

	if (value < rozmiar) // sprawdzenie warunku, czy wprowadzona wartosc jest mniejsza od rozmiaru naszej struktury
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' '; // warunek ktory sprawdza poprawnosc kolejnych elementow kopca i decyduje czy wypisac grafike czy wartosc elementu
		wyswietlKopiec(s + cp, cr, 2 * value + 2);

		s = s.substr(0, sp.length() - 2);

		cout << s << sn << Tab[value] << endl; // wyswietlanie elementu kopca w zaleznosci od wartosci value 

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		wyswietlKopiec(s + cp, cl, 2 * value + 1);
	}
}

void Kopiec::poprawStrukture() {

	//Zmienna pomocnicza do pêtli sortuj¹cej
	int Kopia = 0;

	//Pêtla sortuj¹ca, uk³adaj¹ca elementy kopca w odpowiedniej kolejnoœci
	for (int i = rozmiar; 0 < i; i--) {
		if (Tab[i - 1] < Tab[i]) {
			Kopia = Tab[i - 1];
			Tab[i - 1] = Tab[i];
			Tab[i] = Kopia;
		}


	}


}