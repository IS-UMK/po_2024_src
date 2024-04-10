#ifndef _BAZA_H
#define _BAZA_H

#include <string>
#include <iostream>
#include "osoba.h"

using namespace std;

class Baza
{
    private: 
        Osoba* osoby;
        int ilosc;
        int rozmiar;
    
    public:
        Baza(int rozmiar=100);

        void Dodaj(const Osoba& o);
        friend ostream& operator<<(ostream& o, const Baza& b);

        ~Baza();
};
#endif