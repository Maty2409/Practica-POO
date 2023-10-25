#include "terreno.h"

float Terreno::calcularAmortizacion()
{
    return valor;
}

Terreno::Terreno(int cod_, char tipo_, double valor_)
{
    cod= cod_;
    tipo= tipo_;
    valor= valor_;
}
