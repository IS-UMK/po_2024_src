#include "funkcja.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

#ifndef GAUSS_H
#define	GAUSS_H
class Gauss : public Funkcja
{
protected:
	double srednia;  
	double odchylenie;  
public:	
   Gauss():srednia(0),odchylenie(1) 
   {
   }
	
   Gauss(double srednia,double odchylenie);
	
   double ObliczWartosc(double x) override;
	friend ostream &operator<<(ostream &o,const Gauss &w);
};

#endif
