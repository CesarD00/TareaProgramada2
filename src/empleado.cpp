#include "empleado.h"
#include "persona.h"

Empleado::Empleado(int unaId, Persona* datosPersonales) {
    this->id = unaId;
    this->datosPersona = datosPersonales;
}

Empleado::~Empleado() {
    for(Empleado* empleado : this->empleadosASupervisar) {
        delete empleado;
    }
}

int Empleado::obtenerId() {
    return this->id;
}

Persona* Empleado::obtenerDatosPersona() {
    return this->datosPersona;
}

void Empleado::asignarSupervisor(Empleado* unEmpleado) {
    this->supervisor = unEmpleado;   
}

void Empleado::agregarEmpleadoASupervisar(Empleado* unEmpleado) {
    this->empleadosASupervisar.push_back(unEmpleado);
}