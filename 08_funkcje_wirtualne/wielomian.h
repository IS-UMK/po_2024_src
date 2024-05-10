#include <iostream>
#include "funkcja.h"

using namespace std;

#ifndef _WIELOMIAN_H
#define _WIELOMIAN_H

class Wielomian : public Funkcja
{
   protected:
      int st;
      double *wsp;
      Wielomian(int st);
   public:
      Wielomian();
      Wielomian(double *w,int st);
      Wielomian(const Wielomian&);
      Wielomian Pochodna(int st=1) const;
      ~Wielomian();
      Wielomian& Wczytaj();

	  Wielomian& operator=(const Wielomian &w);
	  Wielomian operator+(const Wielomian &w2) const;
	  Wielomian &operator+=(const Wielomian &w);

	  friend ostream &operator<<(ostream &o,const Wielomian &w);
	  double ObliczWartosc(double x) override;
};

#endif
