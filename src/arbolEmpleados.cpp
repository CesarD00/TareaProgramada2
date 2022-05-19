#include "arbolEmpleados.h"
#include "empleadoNomina.h"
#include "empleado.h"
#include "profesionalPorHoras.h"

#include<iostream>
#include<sstream>
#include<string>

using namespace std;

ArbolEmpleados::ArbolEmpleados(int unId, int unTipo, Persona* personaDirector) {
    this->director = new Empleado(unId, unTipo, personaDirector);
    this->indiceEmpleados.insert(pair<int, Empleado*>(unId, this->director));
}

ArbolEmpleados::ArbolEmpleados() { 
    this->director = nullptr;
}

ArbolEmpleados::~ArbolEmpleados() {
    delete this->director;
}

Empleado* ArbolEmpleados::obtenerEmpleado(int unaId) {
    Empleado* empleadoEncontrado = this->indiceEmpleados.at(unaId);
    return empleadoEncontrado;
}

map<int, Empleado*> ArbolEmpleados::obtenerTodosEmpleados() {
    map<int, Empleado*> todosLosEmpleados = this->indiceEmpleados;
    return todosLosEmpleados;
}

void ArbolEmpleados::agregarDirector(Empleado* unDirector) {
    this->director = unDirector;
    this->indiceEmpleados.insert(pair<int, Empleado*>(unDirector->obtenerId(), this->director));
}

void ArbolEmpleados::agregarEmpleado(int unId, int unTipo, Persona* unaPersona, int idSupervisor) {
    Empleado* nuevoEmpleado = new Empleado(unId, unTipo, unaPersona);

    nuevoEmpleado->asignarSupervisor(this->indiceEmpleados.at(idSupervisor));
    this->indiceEmpleados.at(idSupervisor)->agregarEmpleadoASupervisar(nuevoEmpleado);

    this->indiceEmpleados.insert(pair<int, Empleado*>(unId, nuevoEmpleado));
    
}


void ArbolEmpleados::agregarEmpleado(Empleado* nuevoEmpleado) {
    int idSupervisor = nuevoEmpleado->obtenerSupervisor()->obtenerId();

    nuevoEmpleado->asignarSupervisor(this->indiceEmpleados.at(idSupervisor));
    this->indiceEmpleados.at(idSupervisor)->agregarEmpleadoASupervisar(nuevoEmpleado);

    this->indiceEmpleados.insert(pair<int, Empleado*>(nuevoEmpleado->obtenerId(), nuevoEmpleado));
    
}


istream& operator >> (istream &i, ArbolEmpleados* jerarquiaEmpleados) {
    string linea;
    int id;
    int tipo;
    string nombre;
    string apellido;
    string email;
    int idSupervisor;

    Empleado* nuevoEmpleado;

    while (std::getline(i, linea)) {
        std::istringstream streamLinea(linea);

        streamLinea >> id >> nombre >> apellido >> email >> tipo >> idSupervisor;

        switch(tipo) {
            case 1:
                nuevoEmpleado = new Empleado(id, tipo, new EmpleadoNomina(nombre, apellido, email));
                break;
            case 2:
                nuevoEmpleado = new Empleado(id, tipo, new ProfesionalPorHoras(nombre, apellido, email));
                break;    
        }

        if(id = idSupervisor) {
            jerarquiaEmpleados->agregarDirector(nuevoEmpleado);
        }
        else{
            jerarquiaEmpleados->agregarEmpleado(nuevoEmpleado);
        }
        
    }

    return i;        
}

/*void ArbolEmpleados::toStreamEntradaNomina(istream &i) {
    string linea;

    while(std::getline(i, linea)) {
        istringstream streamLinea(linea);

        streamLinea    
    }
}
*/

ostream& operator << (ostream &o, const ArbolEmpleados* jerarquiaEmpleados) {
    
    for(const auto &empleado : jerarquiaEmpleados->indiceEmpleados) {
        o << empleado.second << endl;
    }

    return o;

}


