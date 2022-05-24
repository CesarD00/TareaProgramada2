#include "reporte.h"
#include "planilla.h"
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
    Planilla* jerarquiaEmpleados = new Planilla();

    *(this->streamEntradaPersonas) >> jerarquiaEmpleados;
    jerarquiaEmpleados->toStreamEntradaNomina(*(this->streamEntradaNomina), jerarquiaEmpleados);
    jerarquiaEmpleados->toStreamEntradaHoras(*(this->streamEntradaProfesionalHoras), jerarquiaEmpleados);

    *(this->streamSalidaReporte) << jerarquiaEmpleados;

    delete jerarquiaEmpleados;


}