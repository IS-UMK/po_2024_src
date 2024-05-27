#include "wyraz.h"
#include <cstdlib>
#include <algorithm>
#include <map>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>


#define MAX 500
using namespace std;

/* Program tworzy slownik wyrazow pojawiajacych sie w tekscie pliku tekstowego. */

/* Funkcja porownujaca dwa wyrazy wzgledem liczby wystapien*/
bool porownaj(pair<Wyraz,int> a, pair<Wyraz,int> b )
{
	return a.second > b.second;
}

// Obiekt funkcyjny, ktory posiada operator porownujacy dwa wyrazy wzgledem liczby znakow
class PorownywatorDlugosci
{
	public:
		bool operator()(pair<Wyraz,int> a, pair<Wyraz,int> b)
		{
			return a.first.Dlugosc() < b.first.Dlugosc();
		}
};

int main()
{
   ifstream plik;
   string nazwa_pliku;

   cout << "Podaj nazwe pliku: " ;
   getline(cin, nazwa_pliku);

   plik.open(nazwa_pliku);
   if(!plik) 
   {
	   cerr << "Blad! Nie moge odczytac pliku: " << nazwa_pliku << endl;
	   return 1;
   }

	Wyraz w;

	// Tworzymy slownik wyrazow z pliku
	map<Wyraz,int> slownik;
	while(plik >> w) slownik[w]++;

	//Wyswietlamy slownik
	map<Wyraz,int>::iterator it;
	for(auto element: slownik)
    {
		cout << element.first << " " <<  element.second << endl;
    }

	if(plik.is_open()) plik.close();

/*  
	std::stringstream ss;      
 
	ss << "!@&#&*(Ala_ma++kota" << endl;
 
	Wyraz w;
	while(!ss.eof())
	{
		ss >> w;
		cout << w << endl;
	}

*/

	//  wypisz 3 najczęściej występujące wrazy. 
	// Wykorzystaj w tym celu algorytm sort oraz funkcję porównującą dwa elementy słownika ze względu na liczbę wystąpień
    
	cout << "\nSortowanie wzgledem liczby wystapien" << endl;

	// kopia elementow slownika do wektora, w ktorym odbedzie sie sortowanie
	vector<pair<Wyraz, int>> v(slownik.begin(), slownik.end()); 
	sort(v.begin(), v.end(), porownaj);
	
	for(auto x: v) 
	{
		cout << x.second << " : " << x.first << endl;
	}


	// trzy najczesciej wystepujace wyraz

	cout << "\nTrzy najczesciej wystepujace wyrazy" << endl;

	int i=0;
	for(it=slownik.begin(); it!=slownik.end() && i<3; it++, i++)
		cout << i+1 << " : " << (*it).second << " : " << (*it).first << endl;

	// wypisz najdłuższy wyraz ze słownika. Wykorzystaj w tym celu algorytm max_element oraz 
	// obiekt funkcyjny służący do porównania dwóch wyrazów ze względu na długość

	auto iter = max_element(slownik.begin(), slownik.end(), PorownywatorDlugosci());
	cout << "\nNajdluzszy wyraz to: " << (*iter).first << ", liczba znakow: " << (*iter).first.Dlugosc() << ", liczba wystapien: " << (*iter).second <<  endl;

	// wypisz w osobnych grupach wyrazy o liczbie znaków n=1, 2, 3, … aż do najdłuższego wyrazu. 
	// Wykorzystaj w tym celu funkcję find_if oraz funkcję lambda sprawdzającą warunek, czy wyraz posiada długość n

	int max_dl = (*iter).first.Dlugosc() ;

	cout << "\ndlugosc : liczba wyrazow" << endl;
	for (int i = 1; i <= max_dl; i++)
	{
		// liczba wyrazow o dlugosci i w slowniku
		auto n = count_if(slownik.begin(), slownik.end(), [i](pair<Wyraz, int> x){return x.first.Dlugosc() == i;});

		if(n == 0 ) continue; // brak wyrazow o dlugosci i

		cout << i << " : " << n << " : "; 

		auto fit = slownik.begin();

		while(fit != slownik.end())
		{
			// szukamy pierwszego wystapienia wyrazu o dlugosci i
			fit = find_if(fit, slownik.end(), [i](pair<Wyraz,int> x){return x.first.Dlugosc() == i;});
			if(fit != slownik.end())
			{
				cout << (*fit).first << ", ";
				fit++;
			}
		}
		
		cout << endl;
	}
	return 0;
}
