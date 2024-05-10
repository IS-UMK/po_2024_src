#include "wielomian.h"

#ifndef LINIA_H
#define LINIA_H

class Linia : public Wielomian
{
public:
	Linia(double a=0, double b=0);
	double MiejsceZerowe() const;
};

#endif
