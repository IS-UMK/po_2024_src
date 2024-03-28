#include "wielomian.h"
#include <iostream>
#include <iomanip>

using namespace std;

Wielomian::Wielomian(int st)
{
	this->st = st;
	this->wsp = new double[st + 1];
}

Wielomian::Wielomian(int st, double* wsp): Wielomian(st)
{
	for (int i = 0; i < st+1; i++)
	{
		this->wsp[i] = wsp[i];
	}
}

Wielomian::Wielomian():Wielomian(0)
{
	wsp[0] = 0.0;
}

Wielomian::Wielomian(const Wielomian& w):Wielomian(w.st)
{
	for (int i = 0; i < w.st + 1; i++)
	{
		this->wsp[i] = w.wsp[i];
	}
}

void Wielomian::Wypisz()
{
	cout << *this;

}

Wielomian::~Wielomian()
{
	if (!wsp)
	{
		delete[] wsp;
		wsp = nullptr;
	}
}

Wielomian Wielomian::Pochodna(int ktora)
{
	if (ktora > st)
	{
		Wielomian w;
		return w;
	}

	if (ktora == 1)
	{
		Wielomian w(st - 1);
		for (int i = 0; i < st; i++)
		{
			w.wsp[i] = this->wsp[i + 1] * (i + 1);
		}
		return w;
	}
	return Pochodna(1).Pochodna(ktora - 1);
}


Wielomian Dodaj(const Wielomian& a, const Wielomian& b)
{
	return a + b;
}

ostream& operator<<(ostream& o, const Wielomian& w)
{
	o << "f(x) = ";
	for (int i = w.st; i > 0; i--)
		if (w.wsp[i] != 0.0)
		{
			if (w.wsp[i] != 1.0) o << showpos << fixed << setprecision(2) 
				<< w.wsp[i] << noshowpos;
			if (i != 1) o << " x^" << i << " ";
			else  o << " x ";
		}

	if (w.wsp[0] != 0 || w.st == 0) o << showpos << w.wsp[0] << noshowpos;
	o << defaultfloat;

	return o;
}


Wielomian& Wielomian::operator=(const Wielomian& w)
{
	if (st != w.st)
	{
		delete[] wsp;
		wsp = new double[w.st + 1];
		st = w.st;
	}
	for (int i = 0; i <= st; i++)
	{
		wsp[i] = w.wsp[i];
	}
	return *this;
}


Wielomian operator+(const Wielomian& a, const Wielomian& b)
{
	int maxst = a.st;
	if (b.st > maxst) maxst = b.st;

	Wielomian w(maxst);
	for (int i = 0; i <= w.st; i++)
		w.wsp[i] = 0.0;

	for (int i = 0; i <= a.st; i++)
		w.wsp[i] += a.wsp[i];

	for (int i = 0; i <= b.st; i++)
		w.wsp[i] += b.wsp[i];

	return w;
}

Wielomian::Wielomian(double x) :Wielomian(0)
{
	wsp[0] = x;
}