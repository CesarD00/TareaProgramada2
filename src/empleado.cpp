#include "empleado.h"
#include "empleadoNomina.h"
#include "profesionalPorHoras.h"

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

Empleado::Empleado(int unaId, int unTipo, Persona* datosPersonales) {
    this->id = unaId;
    this->tipo = unTipo;
    this->datosPersona = datosPersonales;
}

Empleado::Empleado() {
    this->id = 0;
    this->tipo = 0;
    this->datosPersona = nullptr;   
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

void Empleado::toStreamEntrada(string unNombre, string unApellido, string unEmail, int unTipo, istream &entradaNomina, istream &entradaHoras) {
    string linea;

    this->tipo = unTipo;

    EmpleadoNomina* nuevaPersona1;
    ProfesionalPorHoras* nuevaPersona2;

    istringstream streamLinea1;
    istringstream streamLinea2;

    switch(this->tipo) {
        case 1:{
            nuevaPersona1 = new EmpleadoNomina(unNombre, unApellido, unEmail);
            getline(entradaNomina, linea);
            istringstream streamLinea1(linea);
            streamLinea1 >> this->id >> nuevaPersona1;
            this->datosPersona = nuevaPersona1;
            break;
        }  
        case 2:{
            nuevaPersona2 = new ProfesionalPorHoras(unNombre, unApellido, unEmail);
            getline(entradaHoras, linea);
            istringstream streamLinea2(linea);
            streamLinea2 >> this->id >> nuevaPersona2;
            this->datosPersona = nuevaPersona2;
            break; 
        }
             
    }

}

ostream& operator << (ostream &o, const Empleado* empleado) {
    o << empleado->id << "," << empleado->datosPersona->obtenerNombre() << " " << empleado->datosPersona->obtenerApellido() << "," <<
        empleado->supervisor->datosPersona->obtenerNombre() << " " << empleado->supervisor->datosPersona->obtenerApellido() << ",";  

    return o;    
}
