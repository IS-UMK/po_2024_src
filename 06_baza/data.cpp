#include "data.h"

ostream& operator<<(ostream &stream, const Data& d)
{
    return stream << d.dzien << "-" << d.miesiac << "-" << d.rok ; 
}