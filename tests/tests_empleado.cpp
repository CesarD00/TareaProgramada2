#include <gtest/gtest.h>
#include "../src/empleado.h"

#include "../src/empleadoNomina.h"
#include "../src/profesionalPorHoras.h"

namespace {
    TEST(Empleado_Tests, Creacion_Empleado) {
        /// AAA

        // Arange - se configura el escenario
        EmpleadoNomina* persona = new EmpleadoNomina("César", "Díaz", "cesardiaz@mail.mail", 4000);
        Empleado* nuevoEmpleado = new Empleado(2, 1, persona);

        // Act - se ejecuta la operación
        int idActual = nuevoEmpleado->obtenerId();
        int idEsperada = 2;

        Persona* personaActual = nuevoEmpleado->obtenerDatosPersona();
        Persona* personaEsperada = persona;

        delete nuevoEmpleado;
        delete persona;

        // Assert - se validan los resultados
        EXPECT_EQ(idActual, idEsperada);  
        EXPECT_EQ(personaActual, personaEsperada);   
    }

    TEST(Empleado_Tests, Asignar_Supervisor) {
        /// AAA

        // Arange - se configura el escenario
        EmpleadoNomina* personaSupervisor = new EmpleadoNomina("Alejandro", "Fernández", "alejfernandez@mail.mail", 4000);
        Empleado* supervisor = new Empleado(1, 1, personaSupervisor);
        Empleado* nuevoEmpleado = new Empleado(2, 2, new ProfesionalPorHoras("César", "Díaz", "cesardiaz@mail.mail", 50, 30));

        // Act - se ejecuta la operación

        nuevoEmpleado->asignarSupervisor(supervisor);

        int idActual = nuevoEmpleado->obtenerSupervisor()->obtenerId();
        int idEsperada = 1;

        Persona* personaActual = nuevoEmpleado->obtenerSupervisor()->obtenerDatosPersona();
        Persona* personaEsperada = personaSupervisor;

        delete nuevoEmpleado;
        delete supervisor;
        delete personaSupervisor;

        // Assert - se validan los resultados
        EXPECT_EQ(idActual, idEsperada);  
        EXPECT_EQ(personaActual, personaEsperada);   
    }

    TEST(Empleado_Tests, Agregar_Empleados_A_Supervisar) {
        /// AAA

        // Arange - se configura el escenario
        Empleado* supervisor = new Empleado(1, 1, new EmpleadoNomina("Alejandro", "Fernández", "alejfernandez@mail.mail", 4000));
        Empleado* empleado = new Empleado(23, 2, new ProfesionalPorHoras("Valeria", "Martínez", "valemart@mail.mail", 50, 45));

        // Act - se ejecuta la operación

        supervisor->agregarEmpleadoASupervisar(empleado);

        vector<Empleado *> supervisados = supervisor->obtenerEmpleadosASupervisar();

        Empleado* esperado = supervisados[0];

        delete supervisor;

        // Assert - se validan los resultados
        EXPECT_EQ(empleado, esperado);  
    }

    

    

}