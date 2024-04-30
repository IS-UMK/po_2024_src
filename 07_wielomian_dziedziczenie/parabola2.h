#include "parabola.h"

#ifndef PARABOLA2_H
#define PARABOLA2_H

class Parabola2 : public Parabola
{
public:
	Parabola2(double a=0, double b=0, double c=0):Parabola(a,b,c){}
	int Pierwiastki(double * x1, double * x2) const;
};

#endif
