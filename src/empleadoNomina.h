#ifndef EMPLEADONOMINA_H
#define EMPLEADONOMINA_H

#include "persona.h"
#include<istream>

using namespace std;

class EmpleadoNomina : public Persona{

    float pagoMensualBruto;
    float impuestosRetencion;

    public:
    EmpleadoNomina(string nombreEmpleado, string apellidoEmpleado, string emailEmpleado, float unPagoMensual);  
    EmpleadoNomina(string nombreEmpleado, string apellidoEmpleado, string emailEmpleado);   

    virtual float calcularMontoNeto();
    virtual float obtenerImpuestoRetencion();
    friend istream& operator >> (istream &i, EmpleadoNomina* empleado);

    

};


#endif