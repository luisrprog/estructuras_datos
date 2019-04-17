# Makefile para compilar static_queue
all: limpiar programa clean exe

# Compila el programa principal
programa: main.o cola.o
	gcc -o programa main.o cola.o

# Compila el main.c
main.o: main.c cola.h
	gcc -c main.c

# Compila el queue.c
queue.o: cola.c cola.h
	gcc -c cola.c

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