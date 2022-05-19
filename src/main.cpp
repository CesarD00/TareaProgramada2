#include<iostream>
#include "reporte.h"

using namespace std;

int main(){

    cout<<"Hola mundo";

    Reporte* reporteEmpleados = new Reporte();

    reporteEmpleados->generarReporte();

    return 0;
}