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
	g++ -g -o bin/tests bin/tests_empleado_nomina.o bin/empleadoNomina.o bin/tests_profesional_horas.o bin/profesionalPorHoras.o -lgtest -lgtest_main -lpthread		

clean:
	rm -Rf bin	