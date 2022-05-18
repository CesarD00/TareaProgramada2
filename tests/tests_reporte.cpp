#include <gtest/gtest.h>
#include "../src/reporte.h"

#include<iostream>

namespace {
    TEST(Tests_Reporte, Generacion_Reporte){
        /// AAA

        // Arange - se configura el escenario
        string reporte;
        istringstream entradaPersonas("1 César Díaz cesardiaz@mail.mail 1 1\n2Berny Calderón bcald@mail.mail 2 1");
        istringstream entradaNomina("1 4000");
        istringstream entradaProfesionalHoras("2 45 50");
        ostringstream salidaReporte(reporte);

        Reporte* reporteSalario = new Reporte(&entradaPersonas, &entradaNomina, &entradaProfesionalHoras, &salidaReporte);

        // Act - se ejecuta la operación
        reporteSalario->generarReporte();

        string actual = reporte
        string esperado = "ID_Empleado Nombre_Completo Nombre_Supervisor Monto_Neto_A_Pagar\n" + 
                            "1 César Díaz César Diaz 3720\n" +
                            "2 Berny Calderón César Díaz 2250\n" + 
                            "Subtotal Total_Impuestos_A_Retener Total\n" + 
                            "5970 280 6250";

        // Assert - se validan los resultados
        
        EXPECT_EQ(actual, esperado);
    }


}