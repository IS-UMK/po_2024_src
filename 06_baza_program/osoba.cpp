#include "osoba.h"
#include "data.h"
#include <iostream>

using namespace std;

bool Osoba::operator<(const Osoba& o)
{
    if (this->nazwisko < o.nazwisko) return true;
    return false;
}

ostream& operator<<(ostream& stream, const Plec plec)
{
    switch (plec)
    {
    case Plec::Kobieta:
        stream << "Kobieta";
        break;
    case Plec::Mezczyzna:
        stream << "Mezczyzna";
        break;
    
    default:
        stream << "Nieznana plec";
        break;
    }
    return stream;
}

ostream& operator<<(ostream& stream, const Osoba& osoba)
{
    stream << osoba.imiona << ", " << osoba.nazwisko << ", " << osoba.data_urodzenia << ", " << osoba.plec;
    return stream;
}