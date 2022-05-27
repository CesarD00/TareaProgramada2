#include <gtest/gtest.h>
#include "../src/planilla.h"

#include "../src/empleadoNomina.h"
#include "../src/profesionalPorHoras.h"

namespace {
    
    TEST(Planilla_Tests, Agregar_Director) {
        /// AAA

        // Arange - se configura el escenario
        EmpleadoNomina* director = new EmpleadoNomina("César", "Díaz", "cesardiaz@mail.mail", 4000);
        Planilla* empleados = new Planilla(1, 1, director);

        // Act - se ejecuta la operación
        Persona* actual = director;
        Persona* esperada = empleados->obtenerEmpleado(1)->obtenerDatosPersona();

        delete empleados;
        delete director;

        // Assert - se validan los resultados
        EXPECT_EQ(actual, esperada);
    }

    TEST(Planilla_Tests, Agregar_No_Director) {
        /// AAA

        // Arange - se configura el escenario
        Planilla* empleados = new Planilla(1, 1, new EmpleadoNomina("César", "Díaz", "cesardiaz@mail.mail", 4000));
        ProfesionalPorHoras* persona = new ProfesionalPorHoras("Alejandro", "Fernández", "alejfernandez@mail.mail", 50, 34);

        // Act - se ejecuta la operación
        empleados->agregarEmpleado(2, 2, persona, 1);

        Persona* actual = empleados->obtenerEmpleado(2)->obtenerDatosPersona();
        Persona* esperada = persona;

        delete persona;
        delete empleados;

        // Assert - se validan los resultados
        EXPECT_EQ(actual, esperada);
    }    

    TEST(Planilla_Tests, To_Stream_Empleado_Nomina) {
        /// AAA

        // Arange - se configura el escenario
        istringstream i("1 4000\n2 3500");
        Planilla* empleados = new Planilla(1, 1, new EmpleadoNomina("César", "Díaz", "cesardiaz@mail.mail"));
        empleados->agregarEmpleado(new Empleado(2, 1, new EmpleadoNomina("Alejandro", "Fernández", "alejfernandez@mail.mail")), 1);


        // Act - se ejecuta la operación

        empleados->toStreamEntradaNomina(i, empleados);

        float montoActual1 = empleados->obtenerEmpleado(1)->obtenerDatosPersona()->calcularMontoNeto();
        float montoEsperado1 = 3720;

        float montoActual2 = empleados->obtenerEmpleado(2)->obtenerDatosPersona()->calcularMontoNeto();
        float montoEsperado2 = 3255;
        
        delete empleados;

        // Assert - se validan los resultados
        EXPECT_FLOAT_EQ(montoActual1, montoEsperado1);
        EXPECT_FLOAT_EQ(montoActual2, montoEsperado2);
    } 

    TEST(Planilla_Tests, To_Stream_Profesional_Horas) {
        /// AAA

        // Arange - se configura el escenario
        istringstream i("1 40 48\n2 50.76 45");
        Planilla* empleados = new Planilla(1, 2, new ProfesionalPorHoras("César", "Díaz", "cesardiaz@mail.mail"));
        empleados->agregarEmpleado(new Empleado(2, 2, new ProfesionalPorHoras("Alejandro", "Fernández", "alejfernandez@mail.mail")), 1);


        // Act - se ejecuta la operación

        empleados->toStreamEntradaHoras(i, empleados);

        float montoActual1 = empleados->obtenerEmpleado(1)->obtenerDatosPersona()->calcularMontoNeto();
        float montoEsperado1 = 1920;
        float montoActual2 = empleados->obtenerEmpleado(2)->obtenerDatosPersona()->calcularMontoNeto();
        float montoEsperado2 = 2284.2;

        delete empleados;

        // Assert - se validan los resultados
        EXPECT_FLOAT_EQ(montoActual1, montoEsperado1);
        EXPECT_FLOAT_EQ(montoActual2, montoEsperado2);
    } 

}      

