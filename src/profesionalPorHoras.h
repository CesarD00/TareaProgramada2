#ifndef PROFESIONALPORHORAS_H
#define PROFESIONALPORHORAS_H

#include "persona.h"

class ProfesionalPorHoras : public Persona{
    
    float montoPorHora;
    float horasLaboradas;

    public:
    ProfesionalPorHoras(string nombreEmpleado, string apellidoEmpleado, string emailEmpleado, float monto, float horas);

    virtual float calcularMontoNeto();
};


#endif