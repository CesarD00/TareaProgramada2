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

    TEST(Planilla_Tests, Stream_Entrada_Planilla) {
        /// AAA

        // Arange - se configura el escenario
        
        istringstream entradaPersonas("1 César Díaz cesardiaz@mail.mail 1 1\n2 Berny Calderón bcald@mail.mail 2 1");
        istringstream entradaNomina("1 4000");
        istringstream entradaProfesionalHoras("2 32.5 50");

        Planilla* planillaEmpleados = new Planilla();

        // Act - se ejecuta la operación

        planillaEmpleados->toStreamEntrada(entradaPersonas, entradaNomina, entradaProfesionalHoras);

        float montoActual1 = planillaEmpleados->obtenerEmpleado(1)->obtenerDatosPersona()->calcularMontoNeto();
        float montoActual2 = planillaEmpleados->obtenerEmpleado(2)->obtenerDatosPersona()->calcularMontoNeto();

        float montoEsperado1 = 3720;
        float montoEsperado2 = 1625;

        delete planillaEmpleados;

        // Assert - se validan los resultados
        EXPECT_FLOAT_EQ(montoActual1, montoEsperado1); 
        EXPECT_FLOAT_EQ(montoActual2, montoEsperado2); 
    }    
}      

