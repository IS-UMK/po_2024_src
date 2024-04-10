#include "baza.h"
#include "osoba.h"
#include "baza.h"

#include <iostream>
using namespace std;

enum class Opcje {Dodaj=1, Wyswietl=2, Sortuj=3, Zamknij=4, Nieznana };

Opcje menu()
{
    cout << "1. Dodaj\n"
            "2. Wyswietl\n"
            "3. Sortuj\n"
            "4. Zamknij\n" 
            "\nWybierz akcje: " ;

    int odp;
    cin >> odp;
    return (Opcje)odp;
}


int main()
{
    Baza baza;
    baza.Wczytaj();

    Opcje opcje = Opcje::Nieznana;

    while(opcje != Opcje::Zamknij)
    {
        opcje = menu();
        switch (opcje)
        {
        case Opcje::Dodaj:
            {
                string imie, nazwisko;
                int plec;
                int dzien, miesiac, rok;
                cout << "Imie: ";
                cin >> imie;
                cout << "Nazwisko: ";
                cin >> nazwisko;
                cout << "Data urodzenie (dzien miesiac rok): ";
                cin >> dzien >> miesiac >> rok;
                cout << "Plec (0 - Kobieta, 1 - Mezczyzna): ";
                cin >> plec;
                Data data(dzien, miesiac, rok);
                Osoba osoba(nazwisko, imie, data, (Plec)plec);
                baza.Dodaj(osoba);
            }
            break;
        case Opcje::Wyswietl:
            cout << baza << endl;
            break;
        case Opcje::Sortuj:
            baza.Sortuj();
            break;
        case Opcje::Zamknij:
            cout << "Do widzenia." << endl;
            break;
        }
    }

    baza.Zapisz();
}