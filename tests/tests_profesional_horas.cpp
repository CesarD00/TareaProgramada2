#include <gtest/gtest.h>
#include "../src/profesionalPorHoras.h"

namespace {
    
    TEST(Profesional_Horas_Test, Calculo_Monto_Neto){
        /// AAA

        // Arange - se configura el escenario
        ProfesionalPorHoras* empleado = new ProfesionalPorHoras("César", "Díaz", "cesardiaz@mail.mail", 45.6, 60);

        // Act - se ejecuta la operación
        float actual = empleado->calcularMontoNeto();
        float esperada = 2736;

        delete empleado;

        // Assert - se validan los resultados
        EXPECT_FLOAT_EQ(actual, esperada);    
    }

    TEST(Profesional_Horas_Test, Obtener_Impuestos_Retener) {
        /// AAA

        // Arange - se configura el escenario
        ProfesionalPorHoras* empleado = new ProfesionalPorHoras("César", "Díaz", "cesardiaz@mail.mail", 45, 40);

        // Act - se ejecuta la operación

        float actual = empleado->obtenerImpuestoRetencion();
        float esperada = 0;

        delete empleado;

        // Assert - se validan los resultados
        EXPECT_FLOAT_EQ(actual, esperada);
    }

}