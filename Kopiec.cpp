#include "stdafx.h"
#include "Kopiec.h"
#include <iostream>
#include <fstream>

using namespace std;

Kopiec::Kopiec() {
	Kopiec::Tab = NULL;
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
			cout << "Szukana wartosc znajduje sie w kopcu"<< endl;
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



void Kopiec::wyswietlKopiec() {

	system("cls");

	cout << "Aktualny stan kopca:" << endl;
	//Jeżeli tablica nie ma elementów, wyświetl komunikat
	//W przeciwnym wypadku wydrukuj wszystkie elementy tablicy
	if (Tab != NULL) {
		for (int i = 0; i < rozmiar; i++) {
			cout  << i+1 << ". " << Tab[i] << endl;
		}
	}
	else {
		cout << "    Tablica nie ma zadnych elementów" << endl;
	}

}

void Kopiec::poprawStrukture() {

	//Zmienna pomocnicza do pętli sortującej
	int Kopia = 0;

	//Pętla sortująca, układająca elementy kopca w odpowiedniej kolejności
	for (int i = rozmiar; 0 < i; i--) {
		if (Tab[i - 1] < Tab[i]) {
			Kopia = Tab[i - 1];
			Tab[i - 1] = Tab[i];
			Tab[i] = Kopia;
		}


	}


}
