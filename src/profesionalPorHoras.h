#ifndef PROFESIONALPORHORAS_H
#define PROFESIONALPORHORAS_H

#include "persona.h"
#include <iostream>

class ProfesionalPorHoras : public Persona{
    
    float montoPorHora;
    float horasLaboradas;

    public:
    ProfesionalPorHoras(string nombreEmpleado, string apellidoEmpleado, string emailEmpleado, float monto, float horas);
    ProfesionalPorHoras(string nombreEmpleado, string apellidoEmpleado, string emailEmpleado);

    virtual float calcularMontoNeto();
    virtual float obtenerImpuestoRetencion();
    friend istream& operator >> (istream &i, ProfesionalPorHoras* profesional);

};


#endif