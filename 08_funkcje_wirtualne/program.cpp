#include <iostream>
#include "wielomian.h"
#include "linia.h"
#include "parabola.h"
#include "funkcja.h"
#include "gauss.h"

using namespace std;


double calka(Funkcja &f, double a=0.0, double b=1.0, int n=100)
{
	double h = (b-a)/n;
	double wynik = 0.0;

	for (int i=0; i<n; i++)
	{
		wynik += f.ObliczWartosc(a + h * i);
	}
	
	return wynik * h;
}


int main()
{
    int n;

	cout << "Ile wezlow calkowania? " ;
	cin >> n;

	double srednia = 3, odchylenie = 5;
	double a=srednia, b = 3.0 * odchylenie;
	Gauss g(srednia, odchylenie);
	cout << "Funkcja: " << g << endl;
	cout << "Przedzial calkowania: [" << a << ", " << b << "]" << endl; 
	double wynik = calka(g, a, b, n);
	cout << "Wynik calkowania = " << wynik << endl;


	Parabola p(1, 0, 0);
	a = 0.0, b = 1.0;
	cout << "\nFunkcja: " << p << endl;
	wynik = calka(p, a, b, n);
	cout << "Przedzial calkowania: [" << a << ", " << b << "]" << endl; 
	cout << "Wynik calkowania = " << wynik << endl;
	return 0;
}
