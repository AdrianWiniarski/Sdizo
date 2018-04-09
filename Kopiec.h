//#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>

class Kopiec {
protected:
	int *Tab;
	unsigned int rozmiar;


public:
	Kopiec();
	~Kopiec();

	void dodaj(int);
	void usun(int);
	bool sprawdzCzyIstnieje(int);
	void wyswietlKopiec(std::string sp, std::string sn, int value);
	void poprawStrukture();
	bool zaladujzpliku();

};