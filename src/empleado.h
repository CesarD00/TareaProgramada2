#ifndef EMPLEADO_H
#define EMPLEADO_H

#include<string>
#include<vector>
#include<empleado.h>

using namespace std;

class Empleado {
    
    protected:
    int id;
    string nombre;
    string apellido;
    string email;
    int tipoEmpleado;
    Empleado* supervisor;
    vector<Empleado*> empleadosASupervisar;

    public:
    

};


#endif