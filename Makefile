CC  = gcc
INC =
OPC = -g -c
LIB = -pthread
LIBH = -lfl
EXECUTABLES = analizador.out genForkTree.out

.c.o:
	$(CC) $(OPC) $(INC) $<

all: $(EXECUTABLES)

analizador.out: analizador.o
	$(CC) -o $@ $< $(LIBH)

genForkTree.out: genForkTree.o
	$(CC) -o $@ $< $(LIB)

clean:
	rm -fr .codigo_analizado.out .graph.dot *~ *.o $(EXECUTABLES) .out.c

