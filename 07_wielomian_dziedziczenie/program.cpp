#include "parabola.h"
#include "parabola2.h"
#include<iostream>

using namespace std;

int main()
{
	double a = 1.0e-1, b = -1.0e2, c = 1.0e-1;
//	double a = 1.0, b = -6.433, c = 0.009474;

	Parabola p1(a, b, c);
	cout << "Parabola p1 " << p1 << endl;

	double x1, x2;
	int k;

	k = p1.Pierwiastki(&x1, &x2);

	cout << "Ile miejsc zerowych: " << k << endl;

	if(k > 0) 
	{
		cout << "Pierwiastki: x1=" << x1 << " x1=" << x2 << endl;
		cout << "f(x1)=" << p1.ObliczWartosc(x1) << endl;
		cout << "f(x2)=" << p1.ObliczWartosc(x2) << endl;
	}

	Parabola2 p2(a, b, c);

	cout << "Parabola2 p2 " << p2 << endl;

	k = p2.Pierwiastki(&x1, &x2);
	
	cout << "Ile miejsc zerowych: " << k << endl;
	
	if(k > 0) 
	{
		cout << "Pierwiastki: x1=" << x1 << " x1=" << x2 << endl;
		cout << "f(x1)=" << p2.ObliczWartosc(x1) << endl;
		cout << "f(x2)=" << p2.ObliczWartosc(x2) << endl;
	}
}