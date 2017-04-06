#pragma once
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <windows.h>
class Lista
{
public:

	int amount;

	struct doubleList {

		doubleList *next;
		doubleList *prev;
		int data;
	};

	doubleList *head;
	doubleList *tail;
	int counter;


	int wielkosclisty();

	void zaladujzplikulista();

	bool czyjestwsrod(int wartosc);

	void dodajdolisty(int index, int liczba);

	void usunzlisty(int index);

	void wyswietl();
};
