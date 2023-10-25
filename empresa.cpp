#include "empresa.h"
#include <iostream>
#include <fstream>
#include "bien.h"
#include "mueble.h"
#include "terreno.h"
#include "comun.h"
#include <algorithm>

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
Empresa::Empresa()
{

}
