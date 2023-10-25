#include "empresa.h"
#include <iostream>
#include <fstream>
#include "bien.h"
#include "mueble.h"
#include "terreno.h"
#include "comun.h"
#include <algorithm>
#include <map>
#include <numeric>

using namespace std;

void Empresa::addBien(Bien* bien)
    {
        this->bienes.push_back(bien);
    }

void Empresa::calcularAmortizacion()
{
    for_each (bienes.begin(), bienes.end(), [&] (Bien* bien){

           std::cout << bien->calcularAmortizacion() << std::endl;
        
    });
}

void Empresa::leer(const string& filename)
    {
        ifstream archi(filename, ios::binary);
        if (archi.fail())
        {
            cout << "No se pudo abrir el archivo." <<endl;
            return;
        }

        strbien temp;
        while (archi.read((char*)&temp, sizeof(strbien)))
        {
            switch (temp.tipo)
            {
                case 'T':
                    this->bienes.push_back(new Terreno(temp.cod, temp.tipo, temp.valor));
                    break;
                case 'M':
                    this->bienes.push_back(new Mueble(temp.cod, temp.tipo, temp.valor));
                    break;
                case 'C':
                    this->bienes.push_back(new Comun(temp.cod, temp.tipo, temp.valor));
                    break;
                default:
                    cout << "Tipo de bien desconocido." <<endl;
            }
        }

        archi.close();
    }

void Empresa::guardarValoresPostAmortizacion(const std::string& filename)
    {
        std::ofstream file(filename);
        if (!file.is_open())
        {
            std::cout << "Error al abrir el archivo para escritura." << std::endl;
            return;
        }

        for (const auto& bien : bienes)
        {
            file << "codigo " << bien->getCod() << " valor " << bien->getValor() << std::endl;
        }

        file.close();
    }

double Empresa::mayorAmortizacion(){

    sort(this->bienes.begin(), this->bienes.end(),
         [](Bien* e, Bien* e2) -> bool {return (e->getValor() > e2->getValor()); });

    return this->bienes[0]->getValor();
}

void Empresa::imprimirTotales(const std::map<char, double>& totals) {
    std::cout << "Valores totales por tipo de bien:\n";

    for (const auto& [tipo, valor] : totals) {
        std::cout << "Tipo: " << tipo << " - Valor total: " << valor << std::endl;
    }
}

map<char, double> Empresa::valorTotalPorTipo() {
        std::map<char, double> totals;

        for (char tipo : {'T', 'M', 'C'}) {
            totals[tipo] = std::accumulate(this->bienes.begin(),this->bienes.end(), 0.0,
                                           [tipo](double acc, Bien* b) {
                                               return (b->getTipo() == tipo) ? acc + b->getValor() : acc;
                                           });
        }

        return totals;
    }


Empresa::Empresa()
{

}
