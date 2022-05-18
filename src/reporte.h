#ifndef REPORTE_H
#define REPORTE_H

#include<iostream>

class Reporte {

    istream streamEntradaPersonas;
    istream streamEntradaNomina;
    istream streamEntradaProfesionalHoras;
    ostream streamSalidaReporte;

    public:
    Reporte(istream* unaEntradaPersonas, istream* unaEntradaNomina, istream* unaEntradaProfesionalHoras, ostream* unaSalidaReporte);
    
    void generarReporte();

};

#endif