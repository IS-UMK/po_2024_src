#include "parabola2.h"

int Parabola2::Pierwiastki(double *x1, double *x2) const
{
    int k = Parabola::Pierwiastki(x1, x2);

    if(wsp[1] >= 0.0) *x2 = -*x1 - wsp[1]/wsp[2];
    else  *x1 = -*x2 - wsp[1]/wsp[2];

    return k;
}