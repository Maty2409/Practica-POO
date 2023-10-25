#include "mueble.h"

float Mueble::calcularAmortizacion()
{
    if(valor<10000){
        valor=valor-(valor*0.02);
    }else{
        valor= valor- (valor*0.022);
    }
    return valor;
}

Mueble::Mueble(int cod_, char tipo_, double valor_)
{
    cod= cod_;
    tipo= tipo_;
    valor= valor_;
}
