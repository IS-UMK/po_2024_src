#pragma once

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

    Wielomian Pochodna(int ktora = 1);

    void Wypisz();
    ~Wielomian();

    friend Wielomian Dodaj(const Wielomian& a, const Wielomian& b);
};

Wielomian Dodaj(const Wielomian& a, const Wielomian& b);
