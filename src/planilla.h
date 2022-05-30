#ifndef PLANILLA_H
#define PLANILLA_H

#include "empleado.h"
#include "persona.h"
#include <map>

using namespace std;


class Planilla {
    
    Empleado* director;

    map<int, Empleado*> indiceEmpleados;

    public:
    Planilla(int idDirector, int unTipo, Persona* director);
    Planilla();
    ~Planilla();
    void agregarDirector(Empleado* unDirector);
    void agregarEmpleado(int unId, int unTipo, Persona* unaPersona, int idSupervisor);
    void agregarEmpleado(Empleado* nuevoEmpleado, int idSupervisor);
    Empleado* obtenerEmpleado(int unaId);

    void toStreamEntrada(istream &entradaPersonas, istream &entradaNomina, istream &entradaHoras);
    friend ostream& operator << (ostream &o, const Planilla* jerarquiaEmpleados);

};


#endif