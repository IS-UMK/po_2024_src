#include "wyraz.h"
#include <cctype>

Wyraz::Wyraz(const Wyraz &w)
{
	for (int i = 0; i < w.wyraz.size(); i++)
	{
		wyraz.push_back(w.wyraz[i]);
	}
}

ostream & operator<<(ostream &o,const Wyraz &w)
{
	for (int i = 0; i < w.wyraz.size(); i++) o.put(w.wyraz[i]);
	return o;
}

istream & operator>>(istream &i, Wyraz &w)
{
	char c;
	w.wyraz.clear();

	while(i.good() && i.get(c) && !isalpha(c));
	if(!i.good()) return i;

	if(isalpha(c)) w.wyraz.push_back( c );

	while(i.good() && i.get(c) && isalpha(c) )  w.wyraz.push_back( c );
  
	return i;
}
	
bool Wyraz::operator<(const Wyraz &w) const
{
	int min_size = w.wyraz.size() < wyraz.size() ? w.wyraz.size() : wyraz.size();
	for (int i = 0; i < min_size; i++)
	{
		if(tolower(wyraz[i]) != tolower(w.wyraz[i])) return tolower(wyraz[i]) < tolower(w.wyraz[i]);
	}
	return wyraz.size() < w.wyraz.size();
}
