#include "arbolEmpleados.h"
#include "empleado.h"
#include "persona.h"

using namespace std;

ArbolEmpleados::ArbolEmpleados(int unId, Persona* personaDirector) {
    this->director = new Empleado(unId, personaDirector);
    this->indiceEmpleados.insert(pair<int, Empleado*>(unId, this->director));
}

ArbolEmpleados::~ArbolEmpleados() {
    delete this->director;
}

Empleado* ArbolEmpleados::obtenerEmpleado(int unaId) {
    Empleado* empleadoEncontrado = this->indiceEmpleados.at(unaId);
    return empleadoEncontrado;
}

void ArbolEmpleados::agregarEmpleado(int unId, Persona* unaPersona, int idSupervisor) {
    Empleado* nuevoEmpleado = new Empleado(unId, unaPersona);

    nuevoEmpleado->asignarSupervisor(this->indiceEmpleados.at(idSupervisor));
    this->indiceEmpleados.at(idSupervisor)->agregarEmpleadoASupervisar(nuevoEmpleado);

    this->indiceEmpleados.insert(pair<int, Empleado*>(unId, nuevoEmpleado));
    
}


