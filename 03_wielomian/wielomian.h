#pragma once

class Wielomian
{
private:
    int st;
    double* wsp;

public:
    Wielomian();
    Wielomian(int st, double* wsp);
    Wielomian(const Wielomian&);

    Wielomian Pochodna(int ktora = 1);

    void Wypisz();
    ~Wielomian();
};