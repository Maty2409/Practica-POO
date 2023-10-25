#ifndef COMUN_H
#define COMUN_H
#include "bien.h"

class Comun : public Bien
{
public:
    float calcularAmortizacion();
    Comun(int, char, double);
};

#endif // COMUN_H
