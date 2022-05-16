#ifndef PERSONA_H
#define PERSONA_H

#include<string>

using namespace std;

class Persona {
    
    protected:
    string nombre;
    string apellido;
    string email;

    public:
    virtual float calcularMontoNeto() = 0;

};


#endif