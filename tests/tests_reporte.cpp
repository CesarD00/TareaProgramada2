#include <gtest/gtest.h>
#include "../src/reporte.h"

#include<iostream>
#include<string>

namespace {
    TEST(Tests_Reporte, Generacion_Reporte){
        /// AAA

        // Arange - se configura el escenario
        string reporte;
        istringstream entradaPersonas("1 César Díaz cesardiaz@mail.mail 1 1\n2 Berny Calderón bcald@mail.mail 2 1");
        istringstream entradaNomina("1 4000");
        istringstream entradaProfesionalHoras("2 45 50");
        ostringstream salidaReporte;

        Reporte* reporteSalario = new Reporte(&entradaPersonas, &entradaNomina, &entradaProfesionalHoras, &salidaReporte);

        // Act - se ejecuta la operación
        reporteSalario->generarReporte();

        string actual = salidaReporte.str();
        string esperado = string("ID_Empleado,Nombre_Completo,Nombre_Supervisor,Monto_Neto_A_Pagar\n") + 
                            string("1,César Díaz,César Diaz,3720\n") +
                            string("2,Berny Calderón,César Díaz,2250\n") + 
                            string("Subtotal,Total_Impuestos_A_Retener,Total\n") + 
                            string("5970,280,6250");

        // Assert - se validan los resultados
        
        EXPECT_EQ(actual, esperado);

    }


}