#ifndef ARBOLEMPLEADOS_H
#define ARBOLEMPLEADOS_H

#include "empleado.h"
#include "persona.h"
#include <istream>
#include <map>

class ArbolEmpleados {
    
    Empleado* director;

    map<int, Empleado*> indiceEmpleados;

    public:
    ArbolEmpleados(int idDirector, int unTipo, Persona* director);
    ArbolEmpleados();
    ~ArbolEmpleados();
    void agregarDirector(Empleado* unDirector);
    void agregarEmpleado(int unId, int unTipo, Persona* unaPersona, int idSupervisor);
    void agregarEmpleado(Empleado* nuevoEmpleado, int idSupervisor);
    Empleado* obtenerEmpleado(int unaId);
    map<int, Empleado*> obtenerTodosEmpleados();

    void toStreamEntradaNomina(istream &i, ArbolEmpleados* jerarquiaEmpleados);
    void toStreamEntradaHoras(istream &i, ArbolEmpleados* jerarquiaEmpleados);

    friend istream& operator >> (istream &i, ArbolEmpleados* jerarquiaEmpleados);
    friend ostream& operator << (ostream &o, const ArbolEmpleados* jerarquiaEmpleados);

    

};


#endif