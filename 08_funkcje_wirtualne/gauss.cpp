#include "gauss.h"
#include <cmath>
#include <iostream>
#define PI 3.1415926535

static const double pi2=sqrt(2*PI);

Gauss::Gauss(double srednia, double odchylenie)
{
   this->srednia = srednia;
   this->odchylenie = odchylenie;
}

double Gauss::ObliczWartosc(double x)
{
	return exp(-(x-srednia)*(x-srednia)/(2*odchylenie*odchylenie))/(pi2*odchylenie);
}

ostream& operator<<(ostream &o, const Gauss &w)
{
	o << "Gauss (srednia=" << w.srednia << ", odchylenie=" << w.odchylenie << ")";
	return o;
}



