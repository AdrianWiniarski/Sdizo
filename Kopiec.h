#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <windows.h>
class Kopiec
{
protected:
	int rozmiar;
	int* Tab;

public:
	bool zaladujzpliku();
	void dodajdokopca(int value);
	void usunzkopca(int value);
	bool czyjestwsrod(int value);
	void wyswietlkopiec();


	
	//Kopiec();
	//~Kopiec();
};

