#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <windows.h>

#include <string>

struct Element
{
	Element* ostatni;
	Element* nastepny;
	int wartosc;
};

class Lista
{
protected:
	int rozmiar; //rozmiar listy (ilosc elementow'ow)
	Element* poczatek; //wskaznik na glowe listy
	Element* koniec; //wskaznik na ogon listy

public:
	Lista(); //konstruktor bezparametrowy

	~Lista(); //destruktor


	Element* getHead(); //zwraca wskaznik na head

	void StworzL(int val); //dodaje pierwszy element listy;

	int dodajWlos(int val,int index); //dodaje wartosc na losowej pozycji, zwraca wylosowany indeks

	void dodajWpocz(int val); //dodaje wartosc na poczatku - head

	void dodajWkon(int val); //dodaje wartosc na koncu - tail

	int usunWlos(int indeks); //usuwa losowy element, zwraca wylosowany indeks (-1 jesli lista nie istnieje)

	void usunWpocz(); //usuwa head

	void usunWkon(); //usuwa tail

	Element* znajdzL(int index); //zwraca wskaznik na node o danym indeksie - potrzebne do wstawiania w random
							 //sprawdza, czy szybciej bedzie szukac od head do przodu czy od tail do tylu
	int znajdzWart(int val); //wyszukuje dana wartosc w liscie i zwraca indeks node'a
							  //zwraca -1 jesli brak
	bool zaladujzplikuLista(); //wczytywanie z pliku
									 //zwraca true jesli zakonczone powodzeniem, false jesli nie
	void wyswietlListe(); //wyswietlanie listy

	void clear(); //usuwa liste Z JEDNYM ELEMENTEM, ustawia wskazniki na null i rozmiar na 0

	void czyJest(int value);
};
