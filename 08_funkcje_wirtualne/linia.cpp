#include "linia.h"

Linia::Linia(double a, double b):Wielomian(1)
{
	wsp[0]=b;
	wsp[1]=a;
}

double Linia::MiejsceZerowe() const
{
	return (-wsp[0]/wsp[1]);
}

 
