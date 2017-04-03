#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <windows.h>
class Tablica
{
protected:
	int *Tab;
	int rozmiar;
	//int licznik;
public:
	~Tablica();
	Tablica();
	void dodajliczbenak();
	void dodajliczbenap();
	void dodajliczbelos();
	void usunliczbenak();
	void usunliczbenap();
	void usunliczbelos();
	void wypisztablice();
	void Stworz();

};
/*

PASTEBIN
new paste
trends API tools faq
 
Guest User
-
Public Pastes

    untitled5 sec ago
    Untitled5 sec ago
    Untitled10 sec ago
    YElement - a fluen...C# | 11 sec ago
    Untitled11 sec ago
    Untitled19 sec ago
    UntitledC++ | 26 sec ago
    Untitled33 sec ago

SHARE
TWEET
Untitled
a guest Apr 3rd, 2017 22 in 60 min
Not a member of Pastebin yet? Sign Up, it unlocks many cool features!
rawdownloadcloneembedreportprint C++ 1.33 KB

int Tablica::dodajLosowe(int liczba) {
    //wybrane if (indeks >= rozmiar || indeks<0)    return false;       //sprawdz czy ktos nie podal za duzego indeksu
    //wybrane else {
    int indeks;
    if (rozmiar == 0)   indeks = 0;         //unikamy dzielenia przez zero
    else indeks = rand() % rozmiar;
 
   
    int *wskNowy = new int[rozmiar + 1];    //wskaznik na nowa o jeden wieksza tablcie
    wskNowy[indeks] = liczba;               //wstaw zadana liczbe na zadane miejsce
 
    for (int i = 0; i < indeks; i++) {      //do miejsca wstawienia nowej wartosci
        wskNowy[i] = wsk[i];                //przepisz stare
    }
    for (int i = indeks; i < rozmiar; i++) {//kolejne tez przepisz
        wskNowy[i + 1] = wsk[i];
    }
 
    delete[] wsk;               //zwolnij pamiec
    wsk = wskNowy;          //przypisz nowy wskaznik
    wskNowy = nullptr;
    rozmiar++;              //zwieksz rozmiar o jeden
    return indeks;
    //wybrane }
}
 
int Tablica::usunLosowe() {
    if (rozmiar != 0) {
        int indeks;
        if (rozmiar == 0)   indeks = 0;         //unikamy dzielenia przez zero
        else indeks = rand() % rozmiar;
 
        int *wskNowy = new int[rozmiar - 1];
        for (int i = 0; i < indeks; i++) {
            wskNowy[i] = wsk[i];                //przepisz wszystkie wartosci przed indeksem usuwanej wartosci
        }
        for (int i = 0; i < (rozmiar - 1); i++) {
            wskNowy[i] = wsk[i + 1];
        }
 
        delete[] wsk;
        wsk = wskNowy;
        wskNowy = nullptr;
        rozmiar--;
        return indeks;
    }
   

    }

RAW Paste Data
int Tablica::dodajLosowe(int liczba) {
	//wybrane if (indeks >= rozmiar || indeks<0)	return false;		//sprawdz czy ktos nie podal za duzego indeksu
	//wybrane else {
	int indeks;
	if (rozmiar == 0)	indeks = 0;			//unikamy dzielenia przez zero
	else indeks = rand() % rozmiar;

	
	int *wskNowy = new int[rozmiar + 1];	//wskaznik na nowa o jeden wieksza tablcie
	wskNowy[indeks] = liczba;				//wstaw zadana liczbe na zadane miejsce

	for (int i = 0; i < indeks; i++) {		//do miejsca wstawienia nowej wartosci
		wskNowy[i] = wsk[i];				//przepisz stare
	}
	for (int i = indeks; i < rozmiar; i++) {//kolejne tez przepisz
		wskNowy[i + 1] = wsk[i];
	}

	delete[] wsk;				//zwolnij pamiec
	wsk = wskNowy;			//przypisz nowy wskaznik
	wskNowy = nullptr;
	rozmiar++;				//zwieksz rozmiar o jeden
	return indeks;
	//wybrane }
}

int Tablica::usunLosowe() {
	if (rozmiar != 0) {
		int indeks;
		if (rozmiar == 0)	indeks = 0;			//unikamy dzielenia przez zero
		else indeks = rand() % rozmiar;

		int *wskNowy = new int[rozmiar - 1];
		for (int i = 0; i < indeks; i++) {
			wskNowy[i] = wsk[i];				//przepisz wszystkie wartosci przed indeksem usuwanej wartosci
		}
		for (int i = 0; i < (rozmiar - 1); i++) {
			wskNowy[i] = wsk[i + 1];
		}

		delete[] wsk;
		wsk = wskNowy;
		wskNowy = nullptr;
		rozmiar--;
		return indeks;
	}
	
}
create new paste  /  dealsnew!  /  api  /  trends  /  syntax languages  /  faq  /  tools  /  privacy  /  cookies  /  contact  /  dmca  /  scraping  /  go
Site design & logo © 2017 Pastebin; user contributions (pastes) licensed under cc by-sa 3.0 -- Dedicated Server Hosting by Steadfast
Top
x
Learn MoreReal time messaging, file sharing and powerful search. Slack: where work happens.
*/
