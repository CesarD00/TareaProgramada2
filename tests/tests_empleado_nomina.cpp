#include <gtest/gtest.h>
#include "../src/empleadoNomina.h"

namespace {
    TEST(Empleado_Nomina_Test, Calculo_Monto_Neto) {
        /// AAA

        // Arange - se configura el escenario
        EmpleadoNomina* empleado = new EmpleadoNomina("César", "Díaz", "cesardiaz@mail.mail", 4000);

        // Act - se ejecuta la operación
        double actual = empleado->calcularMontoNeto();
        double esperada = 3720;

        delete empleado;

        // Assert - se validan los resultados
        EXPECT_FLOAT_EQ(actual, esperada);
    }   


}