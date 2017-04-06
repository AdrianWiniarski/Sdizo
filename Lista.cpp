#include "stdafx.h"
#include "Lista.h"
#include <fstream>
#include <iostream>

using namespace std;
int Lista::wielkosclisty() {

	return counter;

}

void Lista::zaladujzplikulista() {

	head = tail = NULL;
	doubleList* pom = new doubleList;
	doubleList* tmp = new doubleList;
	fstream plik;
	plik.open("liczby.txt");
	if (plik.good() == false)
		cout << "Plik zostal zle wczytany";
	plik >> amount;
	for (int i = 0; i<amount; i++) {

		tmp = new doubleList;
		plik >> tmp->data;
		tmp->prev = NULL;
		tmp->next = NULL;
		if (head == NULL)
			head = tmp;
		else
		{
			pom = head;
			while (pom->next != NULL)
				pom = pom->next;
			tmp->prev = pom;
			pom->next = tmp;
		}
		counter++;
	}
	tail = tmp;
}

bool Lista::czyjestwsrod(int val) {

	doubleList* e;
	e = head;
	while (e) {
		if (e->data == val)
			return true;
		e = e->next;
	}
	return false;
}

void Lista::dodajdolisty(int index, int liczba) {

	doubleList* p = new doubleList;
	doubleList* n = new doubleList;
	doubleList* e = new doubleList;
	e->data = liczba;
	if (index == 1) {
		e = head->prev;
		e->prev = NULL;
		head = e;
	}
	else {
		if (head)
			p = head;
		for (int i = 0; i<index - 1; i++)
			p = p->next;
		n = p;
		n = n->prev;
		p->prev = e;
		n->next = e;
		e->prev = n;
		e->next = p;
	}
	counter++;
}

void Lista::usunzlisty(int index) {

	doubleList* e = new doubleList;
	doubleList* p = new doubleList;
	doubleList* n = new doubleList;
	if (head) {
		e = head;
		if (index<amount) {
			for (int i = 0; i<index - 1; i++)
				e = e->next;
			if (e == NULL) {
				e = tail;
				tail = tail->prev;
				e = NULL;
				return;
			}
			p = e->prev;
			n = e->next;
			p->next = e->next;
			n->prev = e->prev;
			e = NULL;
			counter--;
			return;
		}
		else
			cout << "Zbyt duzy indeks";
	}
	else
		cout << "Brak listy";
}

void Lista::wyswietl() {
	system("cls");
	int i = 1;
	doubleList* e;
	e = head;
	while (e) {
		cout << i << ". " << e->data << endl;
		e = e->next;
		i++;
	}
};
