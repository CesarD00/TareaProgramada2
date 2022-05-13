#include "empleadoNomina.h"

EmpleadoNomina::EmpleadoNomina(string nombreEmpleado, string apellidoEmpleado, string emailEmpleado, float pagoBrutoMensual){
    this->nombre = nombreEmpleado;
    this->apellido = apellidoEmpleado;
    this->email = emailEmpleado;
    this->pagoMensualBruto = pagoBrutoMensual;
}

float EmpleadoNomina::calcularMontoNeto(){
    return this->pagoMensualBruto-(this->pagoMensualBruto*0.07);
}