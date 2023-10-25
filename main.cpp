#include <iostream>
#include "empresa.h"
#include "bien.h"
#include "terreno.h"
#include "comun.h"
#include "mueble.h"

using namespace std;

int main()
{

    Terreno T1(111, 'T', 30000);
    Comun C1(222, 'C', 10000);
    Mueble M1(333, 'M', 100000);

    cout<<T1.calcularAmortizacion()<<endl;
    cout<<C1.calcularAmortizacion()<<endl;
    cout<<M1.calcularAmortizacion()<<endl;

        return 0;
}
