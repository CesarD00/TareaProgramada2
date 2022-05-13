#ifndef EMPLEADONOMINA_H
#define EMPLEADONOMINA_H

#include "persona.h"

class EmpleadoNomina : public Persona{

    float pagoMensualBruto;

    public:
    EmpleadoNomina(string nombreEmpleado, string apellidoEmpleado, string emailEmpleado, float pagoBrutoMensual);   

    virtual float calcularMontoNeto();

};


#endif