#include "wielomian.h"
#include<iostream>

using namespace std;

int main()
{
	Wielomian w1;

	double x[] = { 1, 2, 3, 4 };

	Wielomian w2(3, x);

	w1.Wypisz();

	w2.Wypisz();


}