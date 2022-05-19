#include "profesionalPorHoras.h"

ProfesionalPorHoras::ProfesionalPorHoras(string nombreEmpleado, string apellidoEmpleado, string emailEmpleado, float monto, float horas){
    this->nombre = nombreEmpleado;
    this->apellido = apellidoEmpleado;
    this->email = emailEmpleado;
    this->montoPorHora = monto;
    this->horasLaboradas = horas;    
}

ProfesionalPorHoras::ProfesionalPorHoras(string nombreEmpleado, string apellidoEmpleado, string emailEmpleado){
    this->nombre = nombreEmpleado;
    this->apellido = apellidoEmpleado;
    this->email = emailEmpleado;
    this->montoPorHora = 0;
    this->horasLaboradas = 0;
}

float ProfesionalPorHoras::calcularMontoNeto(){
    return this->montoPorHora*this->horasLaboradas;
}