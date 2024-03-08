#include "wielomian.h"
#include <iostream>

using namespace std;

Wielomian::Wielomian(int st, double* wsp)
{
	this->st = st;
	this->wsp = new double[st + 1];
	for (int i = 0; i < st+1; i++)
	{
		this->wsp[i] = wsp[i];
	}
}

Wielomian::Wielomian()
{
	st = 0;
	wsp = new double[1];
	wsp[0] = 0.0;
}

Wielomian::Wielomian(const Wielomian& w)
{
	this->st = w.st;
	this->wsp = new double[w.st + 1];
	for (int i = 0; i < w.st + 1; i++)
	{
		this->wsp[i] = w.wsp[i];
	}
}

Wielomian Wielomian::Pochodna(int ktora)
{
	// do zaimplementowania
	return* this;
}

void Wielomian::Wypisz()
{
	// do zaimplementowania
	cout << "Wielomian " << endl;
}

Wielomian::~Wielomian()
{
	delete[] wsp;
}

