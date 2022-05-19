#ifndef REPORTE_H
#define REPORTE_H

#include<istream>
#include<ostream>

using namespace std;

class Reporte {

    istream* streamEntradaPersonas;
    istream* streamEntradaNomina;
    istream* streamEntradaProfesionalHoras;
    ostream* streamSalidaReporte;

    public:
    Reporte(istream* unaEntradaPersonas, istream* unaEntradaNomina, istream* unaEntradaProfesionalHoras, ostream* unaSalidaReporte);
    Reporte();
    
    void generarReporte();

};

#endif