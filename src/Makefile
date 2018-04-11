GOOGLE_TEST_LIB = gtest
GOOGLE_TEST_INCLUDE = /usr/local/include

IDIR =../include

G++ = g++
G++_FLAGS = -c -Wall -fprofile-arcs -ftest-coverage -I $(GOOGLE_TEST_INCLUDE) -I$(IDIR)
LD_FLAGS = -L /usr/local/lib -l $(GOOGLE_TEST_LIB) -l pthread -lgcov

ODIR=obj

_DEPS = arvore.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = arvoretest.o arvore.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(G++) -c -o $@ $< $(G++_FLAGS)

all: $(OBJ)
	g++ -o $@ $^ $(LD_FLAGS)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~


gcov:
	chmod -R 0755 .
	./$(TARGET)
	gcov $(TARGET) -m

