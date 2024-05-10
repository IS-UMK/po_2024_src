#include <iostream>
#include "wielomian.h"
#include <cmath>

using namespace std;

Wielomian::Wielomian() 
{
	st =0;
	wsp = new double[st+1];
	*wsp=0;
}

Wielomian::Wielomian(double *w, int st) 
{
	this->st =st;
	wsp = new double[st+1];
	for(int i=0; i<=st; i++)
		*(wsp+i)=*(w+i);
}

Wielomian::Wielomian(int st)
{
   if(st<0) st = 0;
   this->st=st;
	wsp=new double[st+1];
}

Wielomian::Wielomian(const Wielomian & w) 
{
	this->st=w.st;
	wsp=new double[st+1];
	for(int i=0; i<=st; i++) wsp[i]=w.wsp[i];
}

Wielomian Wielomian::Pochodna(int st) const
{
   if(st==1)
   {

      Wielomian w;
      if(this->st>0)
      {
         w.st=this->st-1;
         delete [] w.wsp;
         w.wsp = new double [w.st+1];

         for(int i=0; i<=w.st; i++)   w.wsp[i]=this->wsp[i+1]*(i+1);
      }
      return w;
   }
   return Pochodna().Pochodna(st-1);
}

Wielomian::~Wielomian()
{
	delete [] wsp;
}

Wielomian Wielomian::operator+(const Wielomian &w1) const
{
   const Wielomian *max=this;
   const Wielomian *min=&w1;
   if(max->st < min->st) 
   {
      max=&w1;
      min=this;
   }
   Wielomian w(*max);
   for(int i=0;i<=min->st;i++) w.wsp[i]+=min->wsp[i];
   return w;
}

Wielomian &Wielomian::operator=(const Wielomian  &w)
{
   if(st!=w.st)
   {
      st=w.st;
      delete [] wsp;
      wsp = new double[st+1];
   }
   for(int i=0;i<=st;i++) wsp[i]=w.wsp[i];
   return *this;
}

ostream &operator<<(ostream &o,const Wielomian &w)
{
	bool wypisane = false;

	o << "f(x) = ";
	for (int i = w.st; i>=0; i--)
   	if (w.wsp[i] != 0)
   	{
   		if (w.wsp[i] > 0.0 && i != w.st ) o << "+";
   		o << w.wsp[i];
   		if (i > 1) o << "x^" << i << " "; 
   		else if ( i == 1 ) o << "x ";
         wypisane=true;
   	}
	if (!wypisane) o << 0;
	return o;
}

Wielomian& Wielomian::Wczytaj()
{
	int st;
	cout << "Stopien wielomianu ?" << endl;
	cin >> st;
	this->st = st;
	this->wsp = new double[st + 1];

	for (int i = st; i >= 0; i--)
	{
		cout << "a[" << i << "]= ";
		cin >> this->wsp[i];
	}
	return *this;
}

Wielomian &Wielomian::operator+=(const Wielomian &w)
{
	return *this = *this + w;
}

double Wielomian::ObliczWartosc(double x)
{
	int i=st;
	double y=wsp[i];
	while ( i>0 ) y = y * x + wsp[--i];
	return y;

}

