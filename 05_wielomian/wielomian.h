#pragma once
#include <iostream>
using namespace std;

class Wielomian
{
private:
    int st;
    double* wsp;

    Wielomian(int st);

public:
    Wielomian();
    Wielomian(int st, double* wsp);
    Wielomian(const Wielomian&);

    Wielomian(double x);

    Wielomian Pochodna(int ktora = 1);

    void Wypisz();
    ~Wielomian();

    Wielomian& operator=(const Wielomian& w);

    friend Wielomian Dodaj(const Wielomian& a, const Wielomian& b);
    friend ostream& operator<<(ostream& o, const Wielomian& w);
    friend Wielomian operator+(const Wielomian& a, const Wielomian& b);
};

