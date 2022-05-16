#ifndef ARBOLEMPLEADOS_H
#define ARBOLEMPLEADOS_H

#include "empleado.h"
#include "persona.h"
#include <map>

class ArbolEmpleados {
    
    Empleado* director;

    map<int, Empleado*> indiceEmpleados;

    public:
    ArbolEmpleados(int idDirector, Persona* director);
    ~ArbolEmpleados();
    void agregarEmpleado(int unId, Persona* unaPersona, int idSupervisor);
    Empleado* obtenerEmpleado(int unaId);

};


#endif