#include <iostream>
#include "empresa.h"
#include "bien.h"
#include "terreno.h"
#include "comun.h"
#include "mueble.h"

using namespace std;

int main()
{

    Empresa Emp1;

    Bien* T1= new Terreno (111, 'T', 30000);
    Bien* C1= new Comun (222, 'C', 10000);
    Bien* M1= new Mueble (333, 'M', 100000);

    Emp1.addBien(T1);
    Emp1.addBien(C1);
    Emp1.addBien(M1);

    Emp1.calcularAmortizacion();
    
    Emp1.guardarValoresPostAmortizacion("valores_post_amortizacion.txt");

    return 0;
}
