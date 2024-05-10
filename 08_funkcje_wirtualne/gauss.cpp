#include "gauss.h"
#include <cmath>
#include <iostream>
#define PI 3.1415926535

double Gauss::ObliczWartosc(double x)
{
	return exp(-(x-srednia) * (x-srednia)/(2.0 * odchylenie * odchylenie))/(sqrt(2.0*PI) * odchylenie);
}

ostream& operator<<(ostream &o, const Gauss &w)
{
	o << "Gauss (srednia=" << w.srednia << ", odchylenie=" << w.odchylenie << ")";
	return o;
}



