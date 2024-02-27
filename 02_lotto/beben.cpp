#include "beben.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

Beben::Beben(int n)
{
    opis = "Beben stworzony";
    this->kule = new int[n];
    rozmiar = n;
    srand(time(NULL));
 }

Beben& Beben::Wypelnij()
{
    for (int i = 0; i < this->rozmiar; i++) 
        this->kule[i] = i+1;
    this->opis = "Beben wypelniony";
    return *this;
}

Beben& Beben::Mieszaj()
{
    int i, k;
    int tmp;
    for ( i = 0; i < this->rozmiar; i++)
    {
        k = rand() % rozmiar;
        tmp = kule[i];
        kule[i] = kule[k];
        kule[k] = tmp;
    }

    opis = "Beben wymieszany";
    return *this;
}

void Beben::Wypisz(int n)
{
    int i;

    cout << opis << endl << "n=" << rozmiar << endl;
    for (i = 0; i < n; i++) cout << kule[i] << " ";
    cout << endl;
}

Beben::~Beben()
{
    cout << "Dziala destruktor" << endl;
    if (kule != nullptr)
    {
        delete[] this->kule;
        kule = nullptr;
    }
    rozmiar = 0;
    opis = "Obiekt zniszczony";
}