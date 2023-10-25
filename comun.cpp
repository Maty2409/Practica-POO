#include "comun.h"

float Comun::calcularAmortizacion()
{
    float aux= valor*0.05;
    valor= valor - aux;

    return valor;
}

Comun::Comun(int cod_, char tipo_, double valor_)
{
    cod= cod_;
    tipo= tipo_;
    valor= valor_;
}
