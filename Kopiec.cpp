#include "stdafx.h"
#include "Kopiec.h"
#include <iostream>
#include <fstream>

using namespace std;

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


void Kopiec::dodajdokopca(int liczba) {

	int j, k;
	int* Kopia = new int[rozmiar + 1];
	for (int i = 0; i<rozmiar; i++)
		Kopia[i] = Tab[i];
	Kopia[rozmiar] = liczba;
	rozmiar++;
	delete[] Tab;
	Tab = Kopia;
	j = rozmiar - 1;
	k = (j - 1) / 2;
	while (j>0 && Tab[k]<liczba) {
		Tab[j] = Tab[k];
		j = k;
		k = (j - 1) / 2;
	}
	Tab[j] = liczba;
}

void Kopiec::usunzkopca(int liczba) {

	int index;
	for (int i = 0; i<rozmiar; i++) {
		if (Tab[i] == liczba)
			index = i;
	}
	int j, k, v;
	v = Tab[rozmiar - 1];
	j = index;
	k = 2 * index + 1;
	Tab[index] = Tab[rozmiar - 1];
	int* Kopia = new int[--rozmiar];
	for (int h = 0; h<rozmiar; h++)
		Kopia[h] = Tab[h];
	delete[] Tab;
	Tab = Kopia;
	while (k<rozmiar - 1)
	{
		if (k + 1 < rozmiar - 1 && Tab[k + 1] > Tab[k]) k++;
		if (v >= Tab[k]) break;
		Tab[j] = Tab[k];
		j = k;
		k = 2 * k + 1;
	}
	Tab[j] = v;
}



void Kopiec::wyswietlkopiec() {
	system("cls");
	for (int i = 0; i<rozmiar; i++)
		cout << i + 1 << ". " << Tab[i] << endl;

}

bool Kopiec::czyjestwsrod(int liczba) {

	for (int i = 0; i<rozmiar; i++) {
		if (Tab[i] == liczba)
			return true;
	}
	return false;

}

