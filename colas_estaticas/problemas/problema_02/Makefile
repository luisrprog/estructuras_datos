
# Makefile para compilar static_queue
all: programa clean exe

# Compila el programa principal
programa: main.o queue.o
	gcc -o programa main.o queue.o

# Compila el main.c
main.o: main.c queue.h
	gcc -c main.c

# Compila el queue.c
queue.o: queue.c queue.h
	gcc -c queue.c

# Limpia los archivos basura
clean:
	rm -f *.o

# Ejejcuta el compilado
exe:
	clear
	@echo successful compilation, running program...
	@echo
	@./programa