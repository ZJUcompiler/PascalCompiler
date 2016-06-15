CC=gcc
IDIR=include
SDIR=src
ODIR=tmp
DFLAGS=-ggdb
CFLAGS=-I$(IDIR)
# LDFLAGS=-l$(LIB1) -l$(LIB2) -l$(LIB3)
CLEANFILES=PasC tmp/*

_DEPS=globals.h util.h y.tab.h
_OBJ=lex.yy.o main.o util.o y.tab.o cgen.o optimize.o
DEPS=$(patsubst %, $(IDIR)/%, $(_DEPS))
OBJ=$(patsubst %, $(ODIR)/%, $(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) $(DFLAGS) -c -o $@ $< $(CFLAGS)

PasC: $(OBJ)
	$(CC) $(DFLAGS) -o $@ $(OBJ) $(CFLAGS) # $(LDFLAGS)

clean:
	rm -f $(CLEANFILES)
