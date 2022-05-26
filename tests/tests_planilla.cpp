#include <gtest/gtest.h>
#include "../src/planilla.h"

#include "../src/empleadoNomina.h"
#include "../src/profesionalPorHoras.h"

namespace {
    
    TEST(Arbol_Empleados_Tests, Agregar_Director) {
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

    TEST(Arbol_Empleados_Tests, Agregar_No_Director) {
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

    TEST(Arbol_Empleados_Tests, To_Stream_Empleado_Nomina) {
        /// AAA

        // Arange - se configura el escenario
        istringstream i("1 4000\n2 3500");
        Planilla* empleados = new Planilla(1, 1, new EmpleadoNomina("César", "Díaz", "cesardiaz@mail.mail"));
        empleados->agregarEmpleado(new Empleado(2, 1, new ProfesionalPorHoras("Alejandro", "Fernández", "alejfernandez@mail.mail")), 1);


        // Act - se ejecuta la operación

        empleados->toStreamEntradaNomina(i, empleados);

        float montoActual1 = static_cast< EmpleadoNomina * >(empleados->obtenerEmpleado(1)->obtenerDatosPersona())->obtenerPagoMensualBruto();
        float montoEsperado1 = 4000;

        float montoActual2 = static_cast< EmpleadoNomina * >(empleados->obtenerEmpleado(2)->obtenerDatosPersona())->obtenerPagoMensualBruto();
        float montoEsperado2 = 3500;
        
        delete empleados;

        // Assert - se validan los resultados
        EXPECT_FLOAT_EQ(montoActual1, montoEsperado1);
        EXPECT_FLOAT_EQ(montoActual2, montoEsperado2);
    } 

    TEST(Arbol_Empleados_Tests, To_Stream_Profesional_Horas) {
        /// AAA

        // Arange - se configura el escenario
        istringstream i("1 40 48\n2 50.76 45");
        Planilla* empleados = new Planilla(1, 2, new EmpleadoNomina("César", "Díaz", "cesardiaz@mail.mail"));
        empleados->agregarEmpleado(new Empleado(2, 2, new ProfesionalPorHoras("Alejandro", "Fernández", "alejfernandez@mail.mail")), 1);


        // Act - se ejecuta la operación

        empleados->toStreamEntradaHoras(i, empleados);

        float montoActual1 = static_cast< ProfesionalPorHoras* >(empleados->obtenerEmpleado(1)->obtenerDatosPersona())->obtenerMontoPorHora();
        float montoEsperado1 = 40;
        float montoActual2 = static_cast< ProfesionalPorHoras* >(empleados->obtenerEmpleado(2)->obtenerDatosPersona())->obtenerMontoPorHora();
        float montoEsperado2 = 50.76;

        float horasActual1 = static_cast< ProfesionalPorHoras * >(empleados->obtenerEmpleado(1)->obtenerDatosPersona())->obtenerHorasLaboradas();
        float horasEsperado1 = 48;
        float horasActual2 = static_cast< ProfesionalPorHoras * >(empleados->obtenerEmpleado(2)->obtenerDatosPersona())->obtenerHorasLaboradas();
        float horasEsperado2 = 45;
        
        delete empleados;

        // Assert - se validan los resultados
        EXPECT_FLOAT_EQ(montoActual1, montoEsperado1);
        EXPECT_FLOAT_EQ(montoActual2, montoEsperado2);
        EXPECT_FLOAT_EQ(horasActual1, horasEsperado1);
        EXPECT_FLOAT_EQ(horasActual2, horasEsperado2);
    } 

}      

