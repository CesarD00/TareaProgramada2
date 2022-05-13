#ifndef EMPLEADO_H
#define EMPLEADO_H

#include<string>
#include<vector>
#include<empleado.h>
#include<persona.h>

using namespace std;

class Empleado {
    
    protected:
    int id;
    Persona* datosPersona;
    Empleado* supervisor;
    vector<Empleado*> empleadosASupervisar;

    public:
    

};


#endif