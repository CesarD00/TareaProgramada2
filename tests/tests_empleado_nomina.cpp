#include <gtest/gtest.h>
#include "../src/empleadoNomina.h"

namespace {
    TEST(Empleado_Nomina_Test, Calculo_Monto_Neto) {
        /// AAA

        // Arange - se configura el escenario
        EmpleadoNomina* empleado = new EmpleadoNomina("César", "Díaz", "cesardiaz@mail.mail", 4000);

        // Act - se ejecuta la operación
        float actual = empleado->calcularMontoNeto();
        float esperada = 3720;

        delete empleado;

        // Assert - se validan los resultados
        EXPECT_FLOAT_EQ(actual, esperada);
    }   

    TEST(Empleado_Nomina_Test, Obtener_Impuestos_Retener) {
        /// AAA

        // Arange - se configura el escenario
        EmpleadoNomina* empleado = new EmpleadoNomina("César", "Díaz", "cesardiaz@mail.mail", 4500);

        // Act - se ejecuta la operación

        empleado->calcularMontoNeto();

        float actual = empleado->obtenerImpuestoRetencion();
        float esperada = 315;

        delete empleado;

        // Assert - se validan los resultados
        EXPECT_FLOAT_EQ(actual, esperada);
    }


}