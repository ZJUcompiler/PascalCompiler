CC=gcc
LEX=lex
YACC=yacc -dtv
IDIR=include
SDIR=src
ODIR=tmp
DFLAGS=-ggdb -Wall
CFLAGS=-I$(IDIR)
# LDFLAGS=-l$(LIB1) -l$(LIB2) -l$(LIB3)
CLEANFILES=PasC parse tmp/* src/*.o

_DEPS=globals.h util.h y.tab.h
_OBJ=lex.yy.o main.o util.o y.tab.o cgen.o optimize.o symbol.o constTab.o x86_new.o
DEPS=$(patsubst %, $(IDIR)/%, $(_DEPS))
OBJ=$(patsubst %, $(ODIR)/%, $(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) $(DFLAGS) -c -o $@ $< $(CFLAGS)

PasC: $(OBJ)
	$(CC) $(DFLAGS) -o $@ $(OBJ) $(CFLAGS) # $(LDFLAGS)

# parse: $(ODIR)/main.o $(ODIR)/util.o $(ODIR)/y.tab.o $(ODIR)/lex.yy.o
# 	$(CC) $(DFLAGS) -o $@ $(CFLAGS) $^

# $(SDIR)/lex.yy.c: Lex_Yacc/pascal.l
	# $(LEX) $<

# $(SDIR)/y.tab.c $(IDIR)/y.tab.h: Lex_Yacc/pascal.y
	# $(YACC) $<

clean:
	rm -f $(CLEANFILES)
