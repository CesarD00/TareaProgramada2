#ifndef EMPLEADONOMINA_H
#define EMPLEADONOMINA_H

#include "persona.h"

class EmpleadoNomina : public Persona{

    float pagoMensualBruto;
    float impuestosRetencion;

    public:
    EmpleadoNomina(string nombreEmpleado, string apellidoEmpleado, string emailEmpleado, float unPagoMensual);  
    EmpleadoNomina(string nombreEmpleado, string apellidoEmpleado, string emailEmpleado);   
    void asignarPagoMensualBruto(float pagoBrutoMensual);
    float obtenerImpuestoRetencion();

    virtual float calcularMontoNeto();

    

};


#endif