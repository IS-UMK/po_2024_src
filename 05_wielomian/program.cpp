#include "wielomian.h"
#include<iostream>

using namespace std;

int main()
{
	Wielomian w1;
	cout << "Wielomian w1 domyslny: " << w1 << endl;
	
	double x[] = { 1, 2.1234 , -3.1, 4 };
	Wielomian w2(3, x);
	cout << "Wielomian w2 stopnia 3: " << w2 << endl;
	
	Wielomian w3;

	w3 = w2;

	cout << "Wielomian w3 (kopia w2):  " << w3 << endl;
	
	cout << "Suma wielomianow w2 + w3 :  " << w2 + w3 << endl;

	cout << "Suma liczby i wielomianu 1.1 + w2 :  " << 1.1 + w2 << endl;

	w3 = w2 + 1.1;

	cout <<  w3 << endl;
}