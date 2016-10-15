CC=gcc
CFLAGS= -Wall -Wno-unused-result -O3 -pedantic

OBJ = ep1.o

default: barrier.o inspector.o cyclist.o ep2.o 
	$(CC) $(CFLAGS) *.o -pthread -o ep2

ep2.o: source/ep2.c
	$(CC) $(CFLAGS) -ansi -c $^

barrier.o: source/barrier/barrier.c source/barrier/barrier.h
	$(CC) $(CFLAGS) -ansi -c $^

cyclist.o: source/cyclist/cyclist.c source/cyclist/cyclist.h
	$(CC) $(CFLAGS) -ansi -c $^

inspector.o: source/inspector/inspector.c source/inspector/inspector.h
	$(CC) $(CFLAGS) -ansi -c $^

clean:
	$(RM) ep2
	$(RM) *.o
	find . -name "*.gch" -type f -delete

# TESTES
srtf:
	# gdb --args ./ep1 2 processos.txt out.txt
	./ep1 2 processos.txt out.txt
	cat out.txt
	$(RM) out.txt ep1