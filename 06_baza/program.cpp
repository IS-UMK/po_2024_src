#include "baza.h"
#include "osoba.h"
#include "baza.h"

#include <iostream>
using namespace std;


int main()
{

    Data data;
    cout << "Data domyslna: " << data << endl;
    
    Data data2(9, 4, 2024);
    cout << "Data dzisiejsza: " << data2 << endl;

    Osoba osoba;
    cout << "Osoba domniemana: " << osoba << endl;
    
    Osoba osoba2("Kowalski", "Jan", data, Plec::Mezczyzna);
    cout << "Osoba 2: " << osoba2 << endl;

    Baza baza;
    cout << "Baza domniemana\n" << baza ;

    baza.Dodaj(osoba);
    baza.Dodaj(osoba2);

    cout << "Baza po dodaniu 2 osob\n" << baza ;

    for (int i = 0; i < 100; i++)
    {
        baza.Dodaj( osoba );
        baza.Dodaj( osoba2 );
    }

    cout << "Baza po dodaniu kolejnych 200 osob\n" << baza ;

}