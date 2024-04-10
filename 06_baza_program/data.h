#ifndef _DATA_H
#define _DATA_H

#include <iostream>

using namespace std;

class Data
{
    private:
        int dzien;
        int miesiac;
        int rok;

    public:
        Data():dzien(1), miesiac(1), rok(1970) { }
        Data(int dzien, int miesiac, int rok):dzien{dzien},miesiac(miesiac),rok{rok} { }
        friend ostream& operator<<(ostream& stream, const Data& osoba);
};

#endif