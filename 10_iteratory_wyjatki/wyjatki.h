#include<string>
#include<iostream>
#include<sstream>

#ifndef _WYJATKI_H
#define _WYJATKI_H

using namespace std;

class Wyjatek
{
protected:
	string tekst;
public:
	Wyjatek(const string s="Wystapila sytuacja wyjatkowa."):tekst(s){};
	virtual string Komunikat(){return "Komunikat: " + tekst + "\n";}
	virtual ~Wyjatek(){};
};

class BrakPamieci: public Wyjatek
{
public:
	BrakPamieci(const string tekst="Brak pamieci"):Wyjatek(tekst) {};
};

class ZlyIndeksWektora: public Wyjatek
{
public:
	int indeks;
	ZlyIndeksWektora(int i=-1,string k="Zly indeks wektora."):Wyjatek(k),indeks(i){};
	string Komunikat(){
		ostringstream s;
		s << "Komunikat: " << tekst << " Indeks=" << indeks << endl;
		return  s.str();
	}
};

#endif
