#include "reporte.h"
#include "arbolEmpleados.h"
#include <iostream>
#include <fstream>

using namespace std;

Reporte::Reporte(istream* entradaPersonas, istream* entradaNomina, istream* entradaProfesionalHoras, ostream* salidaReporte) {
    this->streamEntradaPersonas = entradaPersonas;
    this->streamEntradaNomina = entradaNomina;
    this->streamEntradaProfesionalHoras = entradaProfesionalHoras;
    this->streamSalidaReporte = salidaReporte;
}

Reporte::Reporte() {
    
}

void Reporte::generarReporte() {
    ArbolEmpleados* jerarquiaEmpleados = new ArbolEmpleados();

    *(this->streamEntradaPersonas) >> jerarquiaEmpleados;
    jerarquiaEmpleados->toStreamEntradaNomina(*(this->streamEntradaNomina), jerarquiaEmpleados);

    *(this->streamSalidaReporte) << jerarquiaEmpleados;


}