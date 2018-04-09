#include <fstream>
#include <iostream>
#include <conio.h>
#include <windows.h>

class Tablica
{
protected:
	int *Tab;
	int rozmiar;
	int liczba;
public:
	~Tablica();
	Tablica();
	void dodajliczbenak(int liczba);
	void dodajliczbenap(int liczba);
	void dodajliczbelos(int liczba, int index);
	void usunliczbenak();
	void usunliczbenap();
	void usunliczbelos(int index);
	void wypisztablice();
	void zaladujzpliku();
	void Stworz();
	void szukaj(int val);
};

