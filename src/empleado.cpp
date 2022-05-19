#include "empleado.h"
#include "persona.h"

#include<iostream>

Empleado::Empleado(int unaId, int unTipo, Persona* datosPersonales) {
    this->id = unaId;
    this->tipo = unTipo;
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

int Empleado::obtenerTipo() {
    return this->tipo;
}

Persona* Empleado::obtenerDatosPersona() {
    return this->datosPersona;
}

Empleado* Empleado::obtenerSupervisor() {
    return this->supervisor;
}

vector<Empleado*> Empleado::obtenerEmpleadosASupervisar() {
    return this->empleadosASupervisar;
}

void Empleado::asignarSupervisor(Empleado* unEmpleado) {
    this->supervisor = unEmpleado;   
}

void Empleado::agregarEmpleadoASupervisar(Empleado* unEmpleado) {
    this->empleadosASupervisar.push_back(unEmpleado);
}


ostream& operator << (ostream &o, const Empleado* empleado) {
    o << empleado->id << "," << empleado->datosPersona->obtenerNombre() << "," << empleado->datosPersona->obtenerApellido() << "," <<
        empleado->supervisor->datosPersona->obtenerNombre() << "," << empleado->supervisor->datosPersona->obtenerApellido() << "," <<
        empleado->datosPersona->calcularMontoNeto() << endl;  

    return o;    
}