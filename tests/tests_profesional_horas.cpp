#include <gtest/gtest.h>
#include "../src/profesionalPorHoras.h"

namespace {
    
    TEST(Profesional_Horas_Test, Calculo_Monto_Neto){
        /// AAA

        // Arange - se configura el escenario
        ProfesionalPorHoras* empleado = new ProfesionalPorHoras("César", "Díaz", "cesardiaz@mail.mail", 45.6, 60);
        empleado->asignarMontoPorHora(45.6);
        empleado->asignarHorasLaboradas(60);

        // Act - se ejecuta la operación
        double actual = empleado->calcularMontoNeto();
        double esperada = 2736;

        delete empleado;

        // Assert - se validan los resultados
        EXPECT_FLOAT_EQ(actual, esperada);    
    }

    TEST(Profesional_Horas_Test, Asignar_Obtener_Monto_Por_Hora){
        /// AAA

        // Arange - se configura el escenario
        ProfesionalPorHoras* empleado = new ProfesionalPorHoras("César", "Díaz", "cesardiaz@mail.mail");
        empleado->asignarMontoPorHora(45.6);
        

        // Act - se ejecuta la operación
        double actual = empleado->obtenerMontoPorHora();
        double esperada = 45.6;

        delete empleado;

        // Assert - se validan los resultados
        EXPECT_FLOAT_EQ(actual, esperada);    
    }

    TEST(Profesional_Horas_Test, Asignar_Obtener_Horas_Laboradas){
        /// AAA

        // Arange - se configura el escenario
        ProfesionalPorHoras* empleado = new ProfesionalPorHoras("César", "Díaz", "cesardiaz@mail.mail");
        empleado->asignarHorasLaboradas(60);

        // Act - se ejecuta la operación
        double actual = empleado->obtenerHorasLaboradas();
        double esperada = 60;

        delete empleado;

        // Assert - se validan los resultados
        EXPECT_FLOAT_EQ(actual, esperada);    
    }

}