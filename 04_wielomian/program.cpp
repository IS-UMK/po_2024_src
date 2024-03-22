#include "wielomian.h"
#include<iostream>

using namespace std;

int main()
{
	Wielomian w1;
	cout << "Wielomian domyslny: ";
	w1.Wypisz();
	cout << endl;

	double x[] = { 1, 2.1234 , -3.1, 4 };
	Wielomian w2(3, x);
	cout << "Wielomian w2 stopnia 3: ";
	w2.Wypisz();
	cout << endl;

	Wielomian w3 = w2.Pochodna(1);
	cout << "Pochodna wielomianu w2: ";
	w3.Wypisz();
	cout << endl;

	for (int i = 4; i > 0; i--)
	{
		auto ww = w2.Pochodna(i);
		cout << "Pochodna w2 stopnia " << i << ": ";
		ww.Wypisz();
		cout << endl;
	}

	cout << "Dodawanie wielomianow: " << endl;
	w2.Wypisz();
	cout << endl << " + " << endl;
	
	w3.Wypisz();
	cout << endl << " = " << endl;

	auto w4 = Dodaj(w2, w3);
	w4.Wypisz();
	cout << endl;
}