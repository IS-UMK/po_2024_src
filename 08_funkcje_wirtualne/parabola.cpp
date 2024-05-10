#include "parabola.h"
#include <cmath>

Parabola::Parabola(double a,double b,double c):Wielomian(2)
{
	wsp[0]=c;
	wsp[1]=b;
	wsp[2]=a;
	delta= b*b-4*a*c;
}

double Parabola::Extremum() const
{
	return -wsp[1]/(2*wsp[2]);
}

Parabola::Parabola(const Parabola &p):Wielomian(2)
{
	wsp[0]=p.wsp[0];
	wsp[1]=p.wsp[1];
	wsp[2]=p.wsp[2];
	delta= wsp[1]*wsp[1]-4*wsp[0]*wsp[2];
}

int Parabola::Pierwiastki(double * x1, double * x2) const
{
	if (delta < 0 || (wsp[2] == 0.0 && wsp[1] == 0.0)) return 0;

	if (delta == 0) 
	{
		*x1 = *x2 = Extremum();
		return 1;
	}
	
	if(wsp[2]==0.0) 
	{
		*x1 = *x2 =	-wsp[0]/wsp[1];
		return 1;
	}

	*x1=-(wsp[1]-sqrt(delta))/(2*wsp[2]);
	*x2=-(wsp[1]+sqrt(delta))/(2*wsp[2]);
	return 2;
}

