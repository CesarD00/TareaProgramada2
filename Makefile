FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ -g -o bin/generarReporte bin/main.o

test:
	mkdir -p bin
	g++ $(FLAGS) tests/tests_empleado_nomina.cpp -o bin/tests_empleado_nomina.o
	g++ $(FLAGS) src/empleadoNomina.cpp -o bin/empleadoNomina.o
	g++ $(FLAGS) tests/tests_profesional_horas.cpp -o bin/tests_profesional_horas.o
	g++ $(FLAGS) src/profesionalPorHoras.cpp -o bin/profesionalPorHoras.o
	g++ $(FLAGS) tests/tests_arbol_empleados.cpp -o bin/tests_arbol_empleados.o
	g++ $(FLAGS) src/arbolEmpleados.cpp -o bin/arbolEmpleados.o
	g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o
	g++ -g -o bin/tests bin/tests_empleado_nomina.o bin/empleadoNomina.o bin/tests_profesional_horas.o bin/profesionalPorHoras.o bin/tests_arbol_empleados.o bin/arbolEmpleados.o bin/empleado.o -lgtest -lgtest_main -lpthread		

clean:
	rm -Rf bin	