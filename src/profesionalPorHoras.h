#ifndef PROFESIONALPORHORAS_H
#define PROFESIONALPORHORAS_H

#include "persona.h"

class ProfesionalPorHoras : public Persona{
    
    float montoPorHora;
    float horasLaboradas;

    public:
    ProfesionalPorHoras(string nombreEmpleado, string apellidoEmpleado, string emailEmpleado, float monto, float horas);
    ProfesionalPorHoras(string nombreEmpleado, string apellidoEmpleado, string emailEmpleado);
    void asignarMontoPorHora(float monto);
    void asignarHorasLaboradas(float horas);
    float obtenerMontoPorHora();
    float obtenerHorasLaboradas();

    virtual float calcularMontoNeto();
    virtual float obtenerImpuestoRetencion();

};


#endif