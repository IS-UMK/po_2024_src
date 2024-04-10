#include "baza.h"
#include <algorithm>
#include <fstream>

using namespace std;

Baza::Baza(int rozmiar):rozmiar{rozmiar},ilosc{0}
{
    osoby = new Osoba[rozmiar];
}

Baza::Baza(const Baza &baza):Baza(baza.rozmiar)
{
    ilosc = baza.ilosc;
    for (int i = 0; i < ilosc; i++) osoby[i] = baza.osoby[i];
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

ostream& operator<<(ostream& o, const Baza& b)
{
    o << "Rozmiar: " << b.rozmiar << endl << "Ilosc: " << b.ilosc << endl;
    for (int i = 0; i < b.ilosc; i++)
    {
        o << i+1 << ": " << b.osoby[i] << endl;
    }
    return o;
}

Baza::~Baza()
{
    if(!osoby)
    {
        delete [] osoby;
        osoby = nullptr;
    }
    rozmiar = 0;
    ilosc = 0;
}

Baza &Baza::operator=(const Baza &baza)
{
    if(rozmiar < baza.ilosc)
    {
        delete [] osoby;
        rozmiar = baza.rozmiar;
        osoby = new Osoba[rozmiar];
    }
    ilosc = baza.ilosc;
    for (int i = 0; i < ilosc; i++) osoby[i] = baza.osoby[i];
    return *this;
}

void Baza::Sortuj()
{
    sort(osoby, osoby+ilosc);
}

void Baza::Zapisz(const char *nazwa_pliku)
{
    ofstream plik(nazwa_pliku);
    if (plik.is_open())
    {
        plik << *this;
        plik.close();
        cout << "Baza danych zapisana do pliku: " << nazwa_pliku << endl;
    }
    else cerr << "Problem z otworzeniem pliku:" << nazwa_pliku << endl;
}

Baza &Baza::Wczytaj(const char *nazwa_pliku)
{
    ifstream plik(nazwa_pliku);
    if (plik.is_open())
    {
        string linia;

        // rozmiar
        getline (plik, linia, ':');
        getline (plik, linia);
        rozmiar = stoi(linia);

        // ilosc
        getline (plik, linia, ':');
        getline (plik, linia);
        ilosc = stoi(linia);
        
        delete [] osoby;
        osoby = new Osoba[rozmiar];

        for (int i = 0; i < ilosc; i++)
        {
            getline (plik, linia, ':');
            getline (plik, linia, ','); 
            string imiona=linia;
            
            getline (plik, linia, ','); 
            string nazwisko=linia;
            
            getline (plik, linia, ','); // data dd-mm-yyyy

            auto pos1 = linia.find('-');
            auto pos2 = linia.rfind('-');
            auto dzien = stoi(linia.substr(0, pos1));
            auto miesiac = stoi(linia.substr(pos1+1, pos2));
            auto rok = stoi(linia.substr(pos2+1, string::npos));
            
            getline (plik, linia); // plec

            Plec plec = Plec::Nieznana;
            if(linia.find("Kobieta")  != string::npos) plec = Plec::Kobieta;
            if(linia.find("Mezczyzna")  != string::npos) plec = Plec::Mezczyzna;
            
            osoby[i] = Osoba(nazwisko, imiona, {dzien, miesiac, rok}, plec);
        }
        plik.close();
        cout << "Baza danych wczytana z pliku: " << nazwa_pliku << endl;
    }
    else cerr << "Problem z otworzeniem pliku:" << nazwa_pliku << endl;
    return *this;
}
