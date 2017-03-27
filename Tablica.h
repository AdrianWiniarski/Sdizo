class Tablica
{
protected:
	int *Tab;
	int rozmiar;
	int licznik;
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

};
