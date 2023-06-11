
CC = g++
LD = g++

CFLAGS = -Wall -std=c++11
LFLAGS = -Wall

TRAB2OBJS = main.o vertice.o aresta.o grafo.o

TRABALHOS = ./execTrab2

.cpp.o:
	$(CC) $(CFLAGS) -c $<

all: $(TRABALHOS)

execTrab2: $(TRAB2OBJS)
	$(LD) $(LFLAGS) -o $@ $(TRAB2OBJS) -lm

clean:
	rm -f *.o $(TRABALHOS)
		
