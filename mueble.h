#ifndef MUEBLE_H
#define MUEBLE_H
#include "bien.h"

class Mueble : Bien
{
public:
    float calcularAmortizacion();
    Mueble(int,char, double);
};

#endif // MUEBLE_H
