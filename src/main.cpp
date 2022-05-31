#include<iostream>
#include<fstream>
#include "reporte.h"

using namespace std;

int main(){
    ifstream archivoPersonas("personas.txt", ifstream::in);
    ifstream archivoNomina("nomina.txt", ifstream::in);
    ifstream archivoHorasTrabajadas("horastrabajadas.txt", ifstream::in);
    ofstream reporte("Reporte.csv", ofstream::out);

    if(!reporte.is_open()){
        cerr << "Error leyendo archivo" << endl;
        return -1;
    }

    Reporte* reporteEmpleados = new Reporte(&archivoPersonas, &archivoNomina, &archivoHorasTrabajadas, &reporte);

    reporteEmpleados->generarReporte();

    delete reporteEmpleados;

    reporte.close();
    archivoHorasTrabajadas.close();
    archivoNomina.close();
    archivoPersonas.close();
    
    return 0;

}