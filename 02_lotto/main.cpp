#include "beben.h"
#include <iostream>

using namespace std;

int main()
{
    
    int k, n;

    cout << "k=";
    cin >> k;
    
    cout << "n=";
    cin >> n;

    Beben b(n);
    b.Wypisz(n);

    b.Wypelnij();
    b.Mieszaj();

    b.Wypisz(k);
    // b.~Beben();
    
    return 0;
}
