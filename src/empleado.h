#ifndef EMPLEADO_H
#define EMPLEADO_H

#include<string>
#include<vector>
#include "persona.h"

using namespace std;

class Empleado {
    
    int id;
    int tipo;
    Persona* datosPersona;
    Empleado* supervisor;
    vector<Empleado*> empleadosASupervisar;

    public:
    Empleado(int unaId, int unTipo, Persona* datosPersonales);
    Empleado();
    ~Empleado();

    void asignarSupervisor(Empleado* unSupervisor);
    void agregarEmpleadoASupervisar(Empleado* unEmpleado);
    int obtenerId();
    int obtenerTipo();
    Empleado* obtenerSupervisor();
    vector<Empleado*> obtenerEmpleadosASupervisar();
    Persona* obtenerDatosPersona();

    void toStreamEntrada(string unNombre, string unApellido, string unEmail, int unTipo, istream &entradaNomina, istream &entradaHoras);
    friend ostream& operator << (ostream &o, const Empleado* empleado);
    
};


#endif