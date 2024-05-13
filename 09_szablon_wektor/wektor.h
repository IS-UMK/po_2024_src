#ifndef _WEKTOR_H
#define _WEKTOR_H

#include <iostream>

using namespace std;

const int domyslny_rozmiar = 20;

template <typename T>
class Wektor
{
protected:
	T* elementy;
	int rozmiar;
	int liczba_elementow;
	
public:
	Wektor() :Wektor(domyslny_rozmiar) {}
	Wektor(const Wektor<T>& w);
	Wektor(int rozmiar):elementy{ new T[rozmiar] }, 
		rozmiar{ rozmiar }, liczba_elementow{0} {};
	
	int Rozmiar() const { return rozmiar;  }
	int IleElementow() const { return liczba_elementow;  }
	T& operator[](int indeks) { return elementy[indeks]; }

	void Dodaj(const T& t);
	void Usun();
	void Wyczysc() { liczba_elementow = 0; }

	~Wektor();
	
	Wektor<T>& operator=(const Wektor<T>& t);

	template <typename U>
	friend ostream& operator<<(ostream& o, const Wektor<U>& w);
};

template <typename T>
void Wektor<T>::Dodaj(const T& t)
{
	if (rozmiar == liczba_elementow)
	{
		rozmiar = rozmiar * 2;
		T* nowa = new T[rozmiar];
		for (int i = 0; i < liczba_elementow; i++)
		{
			nowa[i] = elementy[i];
		}
		delete[] elementy;
		elementy = nowa;
	}
	elementy[liczba_elementow] = t;
	liczba_elementow++;
}

template <typename T>
ostream& operator<<(ostream& o, const Wektor<T> &w)
{
	o << "Wektor o rozmiarze: " << w.rozmiar << endl;
	o << "Ile elementow: " << w.liczba_elementow << endl;
	o << "Elementy: ";
	for (int i = 0; i < w.liczba_elementow; i++)
	{
		o << w.elementy[i] << ", ";
	}
	return o;
}

template <typename T>
void Wektor<T>::Usun()
{
	if (liczba_elementow > 0) liczba_elementow--;
}

template <typename T>
Wektor<T>::~Wektor()
{
	if (elementy)
	{
		delete[] elementy;
		elementy = nullptr;
	}
}

template <typename T>
Wektor<T>::Wektor(const Wektor<T>& w):Wektor(w.rozmiar)
{
	liczba_elementow = w.liczba_elementow;
	for (int i = 0; i < liczba_elementow; i++)
	{
		elementy[i] = w.elementy[i];
	}
}
template <typename T>
Wektor<T>& Wektor<T>::operator=(const Wektor<T>& w)
{
	if (rozmiar < w.liczba_elementow)
	{
		rozmiar = w.rozmiar;
		delete[] elementy;
		elementy = new T[rozmiar];
	}
	liczba_elementow = w.liczba_elementow;
	for (int i = 0; i < w.liczba_elementow; i++)
		elementy[i] = w.elementy[i];
	
	return  *this;
}
#endif