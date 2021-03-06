#include "empleadoNomina.h"

EmpleadoNomina::EmpleadoNomina(string nombreEmpleado, string apellidoEmpleado, string emailEmpleado, float unPagoMensual) {
    this->nombre = nombreEmpleado;
    this->apellido = apellidoEmpleado;
    this->email = emailEmpleado;
    this->pagoMensualBruto = unPagoMensual; 
    this->impuestosRetencion = 0;
}

EmpleadoNomina::EmpleadoNomina(string nombreEmpleado, string apellidoEmpleado, string emailEmpleado){
    this->nombre = nombreEmpleado;
    this->apellido = apellidoEmpleado;
    this->email = emailEmpleado;
    this->pagoMensualBruto = 0;
    this->impuestosRetencion = 0;
}

float EmpleadoNomina::obtenerImpuestoRetencion() {
    return this->impuestosRetencion;
}

float EmpleadoNomina::calcularMontoNeto(){
    this->impuestosRetencion = this->pagoMensualBruto*0.07;
    return this->pagoMensualBruto - this->impuestosRetencion;
}

istream& operator >> (istream &i, EmpleadoNomina* empleado) {
    i >> empleado->pagoMensualBruto;

    return i;
}
