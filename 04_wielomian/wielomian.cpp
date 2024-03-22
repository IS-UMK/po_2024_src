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
	cout << "f(x) = ";
	for(int i=st; i>0; i--)
		if(wsp[i]!=0.0) 
		{
			 if(wsp[i]!=1.0) cout << showpos << fixed << setprecision(2) << wsp[i] << noshowpos  ;
			 if(i!=1) cout << " x^"  << i  << " "; 
             else  cout << " x " ;
		}
	
	if (wsp[0]!=0 || st==0) cout << showpos << wsp[0] << noshowpos ;
   cout << defaultfloat ;
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



