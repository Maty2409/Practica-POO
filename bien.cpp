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

int Bien::getCod() const
{
    return cod;
}

void Bien::setCod(int newCod)
{
    cod = newCod;
}

char Bien::getTipo() const
{
    return tipo;
}

void Bien::setTipo(char newTipo)
{
    tipo = newTipo;
}

Bien::Bien(int _cod, char _tipo, double _valor)
{
      this->cod=_cod;
      this->tipo= _tipo;
      this->valor= _valor;
}
