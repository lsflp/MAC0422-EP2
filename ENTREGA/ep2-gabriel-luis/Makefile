#  Nomes: Gabriel Capella                       Números USP: 8962078 
#         Luís Felipe de Melo Costa Silva                    9297961

C=gcc
CFLAGS= -Wall -Wno-unused-result -O3 -pedantic

OBJ = ep1.o

default: barrier.o inspector.o cyclist.o ep2.o 
	$(CC) $(CFLAGS) *.o -pthread -o ep2

ep2.o: codigo/ep2.c
	$(CC) $(CFLAGS) -ansi -c $^

barrier.o: codigo/barrier/barrier.c codigo/barrier/barrier.h
	$(CC) $(CFLAGS) -ansi -c $^

cyclist.o: codigo/cyclist/cyclist.c codigo/cyclist/cyclist.h
	$(CC) $(CFLAGS) -ansi -c $^

inspector.o: codigo/inspector/inspector.c codigo/inspector/inspector.h
	$(CC) $(CFLAGS) -ansi -c $^

clean:
	$(RM) ep2
	$(RM) *.o
	find . -name "*.gch" -type f -delete