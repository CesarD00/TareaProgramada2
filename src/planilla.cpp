#include "planilla.h"
#include "empleadoNomina.h"
#include "profesionalPorHoras.h"

#include<iostream>
#include<sstream>
#include<string>
#include<iomanip>

using namespace std;

Planilla::Planilla(int unId, int unTipo, Persona* personaDirector) {
    this->director = new Empleado(unId, unTipo, personaDirector);
    this->indiceEmpleados.insert(pair<int, Empleado*>(unId, this->director));
}

Planilla::Planilla() { 
    this->director = nullptr;
}

Planilla::~Planilla() {
    delete this->director;
}

Empleado* Planilla::obtenerEmpleado(int unaId) {
    Empleado* empleadoEncontrado = this->indiceEmpleados.at(unaId);
    return empleadoEncontrado;
}

map<int, Empleado*> Planilla::obtenerTodosEmpleados() {
    map<int, Empleado*> todosLosEmpleados = this->indiceEmpleados;
    return todosLosEmpleados;
}

void Planilla::agregarDirector(Empleado* unDirector) {
    this->director = unDirector;
    this->indiceEmpleados.insert(pair<int, Empleado*>(unDirector->obtenerId(), this->director));
    this->director->asignarSupervisor(this->director);
}

void Planilla::agregarEmpleado(int unId, int unTipo, Persona* unaPersona, int idSupervisor) {
    Empleado* nuevoEmpleado = new Empleado(unId, unTipo, unaPersona);

    nuevoEmpleado->asignarSupervisor(this->indiceEmpleados.at(idSupervisor));
    this->indiceEmpleados.at(idSupervisor)->agregarEmpleadoASupervisar(nuevoEmpleado);

    this->indiceEmpleados.insert(pair<int, Empleado*>(unId, nuevoEmpleado));
    
}

void Planilla::agregarEmpleado(Empleado* nuevoEmpleado, int idSupervisor) {

    nuevoEmpleado->asignarSupervisor(this->indiceEmpleados.at(idSupervisor));
    this->indiceEmpleados.at(idSupervisor)->agregarEmpleadoASupervisar(nuevoEmpleado);

    this->indiceEmpleados.insert(pair<int, Empleado*>(nuevoEmpleado->obtenerId(), nuevoEmpleado));

}

void Planilla::toStreamEntrada(istream &entradaPersonas, istream &entradaNomina, istream &entradaHoras){
    string linea;
    int id;
    string nombre;
    string apellido;
    string email;
    int tipo;
    int idSupervisor;

    while (getline(entradaPersonas, linea)) {
        istringstream streamLinea(linea);

        streamLinea >> id >> nombre >> apellido >> email >> tipo >> idSupervisor;

        Empleado* nuevoEmpleado = new Empleado();

        nuevoEmpleado->toStreamEntrada(nombre, apellido, email, tipo, entradaNomina, entradaHoras);

        if(nuevoEmpleado->obtenerId() == idSupervisor) {
            this->agregarDirector(nuevoEmpleado);
        }
        else{
            this->agregarEmpleado(nuevoEmpleado, idSupervisor);
        }
    }      
}

ostream& operator << (ostream &o, const Planilla* jerarquiaEmpleados) {
    float subtotal {};
    float monto {};
    float totalImpuestos {};
    float total {};
    o << "ID_Empleado,Nombre_Completo,Nombre_Supervisor,Monto_Neto_A_Pagar" << endl;

    for(const auto &empleado : jerarquiaEmpleados->indiceEmpleados) {
        monto = empleado.second->obtenerDatosPersona()->calcularMontoNeto();

        o << empleado.second << monto << endl;

        totalImpuestos = totalImpuestos + empleado.second->obtenerDatosPersona()->obtenerImpuestoRetencion();

        subtotal = subtotal + monto;
    }

    total = subtotal + totalImpuestos;

    o << "\nSubtotal,Total_Impuestos_A_Retener,Total" << endl;
    o << setprecision(2) << fixed << subtotal << "," << setprecision(2) << fixed << totalImpuestos << "," << setprecision(2) << fixed << total;

    return o;

}




