#ifndef TERRENO_H
#define TERRENO_H
#include "bien.h"

class Terreno : public Bien
{
public:
    float calcularAmortizacion();
    Terreno(int, char, double);
};

#endif // TERRENO_H
