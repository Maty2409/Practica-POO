#include "bien.h"

Bien::Bien(){

}

double Bien::getValor() const
{
    return valor;
}

void Bien::setValor(double newValor)
{
    valor = newValor;
}

Bien::Bien(int _cod, char _tipo, double _valor)
{
      this->cod=_cod;
      this->tipo= _tipo;
      this->valor= _valor;
}
