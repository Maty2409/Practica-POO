#ifndef EMPRESA_H
#define EMPRESA_H
#include "bien.h"
#include <vector>
#include <iostream>

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
    void leer(const std::string& filename);
    Empresa();
};

#endif // EMPRESA_H
