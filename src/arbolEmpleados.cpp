#include "arbolEmpleados.h"
#include "empleadoNomina.h"
#include "empleado.h"
#include "profesionalPorHoras.h"

#include<iostream>
#include<istream>
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
    this->director->asignarSupervisor(this->director);
}

void ArbolEmpleados::agregarEmpleado(int unId, int unTipo, Persona* unaPersona, int idSupervisor) {
    Empleado* nuevoEmpleado = new Empleado(unId, unTipo, unaPersona);

    nuevoEmpleado->asignarSupervisor(this->indiceEmpleados.at(idSupervisor));
    this->indiceEmpleados.at(idSupervisor)->agregarEmpleadoASupervisar(nuevoEmpleado);

    this->indiceEmpleados.insert(pair<int, Empleado*>(unId, nuevoEmpleado));
    
}

void ArbolEmpleados::agregarEmpleado(Empleado* nuevoEmpleado, int idSupervisor) {

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
        istringstream streamLinea(linea);

        streamLinea >> id >> nombre >> apellido >> email >> tipo >> idSupervisor;

        switch(tipo) {
            case 1:
                nuevoEmpleado = new Empleado(id, tipo, new EmpleadoNomina(nombre, apellido, email));
                break;
            case 2:
                nuevoEmpleado = new Empleado(id, tipo, new ProfesionalPorHoras(nombre, apellido, email));
                break;    
        }

        if(id == idSupervisor) {
            jerarquiaEmpleados->agregarDirector(nuevoEmpleado);
        }
        else{
            jerarquiaEmpleados->agregarEmpleado(nuevoEmpleado, idSupervisor);
        }
        
    }

    return i;        
}

void ArbolEmpleados::toStreamEntradaNomina(istream &i, ArbolEmpleados* jerarquiaEmpleados) {
    string linea;
    int id;
    float pago;

    while(std::getline(i, linea)) {
        istringstream streamLinea(linea);

        streamLinea >> id >> pago;

        static_cast< EmpleadoNomina * >(jerarquiaEmpleados->indiceEmpleados.at(id)->obtenerDatosPersona())->asignarPagoMensualBruto(pago);
  
    }
        
}

ostream& operator << (ostream &o, const ArbolEmpleados* jerarquiaEmpleados) {
    float subtotal;
    float monto;
    float totalImpuestos = 280;
    float total;
    o << "ID_Empleado,Nombre_Completo,Nombre_Supervisor,Monto_Neto_A_Pagar" << endl;

    for(const auto &empleado : jerarquiaEmpleados->indiceEmpleados) {
        monto = empleado.second->obtenerDatosPersona()->calcularMontoNeto();

        o << empleado.second << monto << endl;

        subtotal += monto;
    }

    total = subtotal + totalImpuestos;

    o << "Subtotal,Total_Impuestos_A_Retener,Total" << endl;
    o << subtotal << "," << "280" << "," << total;

    return o;

}


