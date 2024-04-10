#ifndef _OSOBA_H
#define _OSOBA_H

#include <string>
#include <iostream>
#include "data.h"

using namespace std;

enum class Plec {Kobieta, Mezczyzna, Nieznana};

class Osoba
{
    private:
        string nazwisko; 
        string imiona;
        Data data_urodzenia;
        Plec plec;

    public:
        Osoba(const char* nazwisko, const char* imiona, const Data& data_urodzenia, Plec plec):
            nazwisko{nazwisko},imiona{imiona},data_urodzenia{data_urodzenia}, plec{plec} { }
        Osoba():nazwisko{""},imiona{""},plec{Plec::Nieznana} { }
        
        friend ostream& operator<<(ostream& stream, const Osoba& osoba);
};
#endif