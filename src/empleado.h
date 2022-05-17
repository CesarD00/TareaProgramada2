#ifndef EMPLEADO_H
#define EMPLEADO_H

#include<string>
#include<vector>
#include "persona.h"

using namespace std;

class Empleado {
    
    protected:
    int id;
    Persona* datosPersona;
    Empleado* supervisor;
    vector<Empleado*> empleadosASupervisar;

    public:
    Empleado(int unaId, Persona* datosPersonales);
    ~Empleado();

    void asignarSupervisor(Empleado* unSupervisor);
    void agregarEmpleadoASupervisar(Empleado* unEmpleado);
    int obtenerId();
    Empleado* obtenerSupervisor();
    vector<Empleado*> obtenerEmpleadosASupervisar();
    Persona* obtenerDatosPersona();
    

};


#endif