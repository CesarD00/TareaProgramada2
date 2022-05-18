#include "reporte.h"

Reporte::Reporte(istream* entradaPersonas, istream* entradaNomina, istream* entradaProfesionalHoras, ostream* salidaReporte) {
    this->streamEntradaPersonas = entradaPersonas;
    this->streamEntradaNomina = entradaNomina;
    this->streamEntradaProfesionalHoras = entradaProfesionalHoras;
    this->streamSalidaReporte = salidaReporte;
}

void Reporte::generarReporte() {
    
}