all: simulador.o
	g++ -Wall simulador.o -o main -g
	make clean

simulador.o: simulador.cpp
	g++ -Wall -c simulador.cpp -o simulador.o
	
clean:
	rm *.o