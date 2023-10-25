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

    Terreno T1(111, 'T', 30000);
    Comun C1(222, 'C', 10000);
    Mueble M1(333, 'M', 100000);

    Emp1.addBien(T1);
    Emp1.addBien(C1);
    Emp1.addBien(M1);

    Emp1.calcularAmortizacion();
    
    

    return 0;
}
