FLAGS = -g -c --std=c++17

version_debug:
	mkdir -p bin
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	g++ -g -o bin/generarReporte bin/main.o

clean:
	rm -Rf bin	