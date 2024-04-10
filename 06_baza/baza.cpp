#include "baza.h"
#include <algorithm>
#include <fstream>

using namespace std;

Baza::Baza(int rozmiar):rozmiar{rozmiar},ilosc{0}
{
    osoby = new Osoba[rozmiar];
}

void Baza::Dodaj(const Osoba &osoba)
{
    if(ilosc == rozmiar)
    {
        rozmiar *= 2;
        Osoba *nowe_osoby = new Osoba[rozmiar];
        for (int i = 0; i < ilosc; i++)
        {
            nowe_osoby[i] = osoby[i];
        }
        delete [] osoby;
        osoby = nowe_osoby;
    }
    osoby[ilosc] = osoba;
    ilosc++;   
}

Baza::~Baza()
{
    if(!osoby)
    {
        delete [] osoby;
        osoby = nullptr;
    }
    ilosc = 0;
    rozmiar = 0;
}

ostream& operator<<(ostream& o, const Baza& b)
{
    o << "Rozmiar: " << b.rozmiar << endl << "Ilosc: " << b.ilosc << endl;
    for (int i = 0; i < b.ilosc; i++)
    {
        o << i+1 << ": " << b.osoby[i] << endl;
    }
    return o;
}