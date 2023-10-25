#ifndef EMPRESA_H
#define EMPRESA_H
#include "bien.h"
#include <vector>
#include <iostream>
#include <map>

struct strbien{
    int cod;
    char tipo;
    double valor;
};

class Empresa
{
private:
    std::vector <Bien* > bienes;
public:
    void addBien(Bien* bien);
    void calcularAmortizacion();
    void leer(const std::string& filename);
    void guardarValoresPostAmortizacion(const std::string& filename);
    double mayorAmortizacion();
    std::map<char, double> valorTotalPorTipo();
    void imprimirTotales(const std::map<char, double>& totals);
    Empresa();
    
};

#endif // EMPRESA_H
