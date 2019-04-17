# Makefile para compilar static_queue
all: limpiar programa clean exe

# Compila el programa principal
programa: main.o pilad.o
	gcc -o programa main.o pilad.o

# Compila el main.c
main.o: main.c pilad.h
	gcc -c main.c

# Compila el queue.c
stack.o: pilad.c pilad.h
	gcc -c pilad.c

# Limpia los archivos basura
clean:
	rm -f *.o
# Limpia la terminal
limpiar:
	clear

# Ejejcuta el compilado
exe:
	@echo Compilacion exitosa, ejecutando programa:
	@echo
	@./programa
