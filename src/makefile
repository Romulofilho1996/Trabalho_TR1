IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -Wall

ODIR=obj
LIBS=-lm

_DEPS = fisica.hpp enlace.hpp wraper.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = simulador.o fisica.o enlace.o wraper.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

simulador: $(OBJ)
	$(CC) -std=c++11 -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ simulador *~