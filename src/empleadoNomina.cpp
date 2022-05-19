#include "empleadoNomina.h"

EmpleadoNomina::EmpleadoNomina(string nombreEmpleado, string apellidoEmpleado, string emailEmpleado, float unPagoMensual) {
    this->nombre = nombreEmpleado;
    this->apellido = apellidoEmpleado;
    this->email = emailEmpleado;
    this->pagoMensualBruto = unPagoMensual; 
}

EmpleadoNomina::EmpleadoNomina(string nombreEmpleado, string apellidoEmpleado, string emailEmpleado){
    this->nombre = nombreEmpleado;
    this->apellido = apellidoEmpleado;
    this->email = emailEmpleado;
    this->pagoMensualBruto = 0;
}

void EmpleadoNomina::asignarPagoMensualBruto(float pagoBrutoMensual) {
    this->pagoMensualBruto = pagoBrutoMensual;
}

float EmpleadoNomina::calcularMontoNeto(){
    return this->pagoMensualBruto-(this->pagoMensualBruto*0.07);
}
