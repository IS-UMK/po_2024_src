#ifndef _BAZA_H
#define _BAZA_H

#include <string>
#include <iostream>
#include "osoba.h"

#define PLIK_BAZY "baza.txt"

using namespace std;

class Baza
{
    private: 
        Osoba* osoby;
        int ilosc;
        int rozmiar;
    
    public:
        Baza(int rozmiar=100);
        Baza(const Baza& baza);

        void Dodaj(const Osoba& o);
        friend ostream& operator<<(ostream& o, const Baza& b);

        void Sortuj();

        void Zapisz(const char* nazwa_pliku=PLIK_BAZY);
        Baza& Wczytaj(const char* nazwa_piliku=PLIK_BAZY);

        ~Baza();

        Baza& operator=(const Baza& baza);
};
#endif