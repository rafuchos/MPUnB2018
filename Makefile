GOOGLE_TEST_LIB = gtest
GOOGLE_TEST_INCLUDE = /usr/local/include

G++ = g++
G++_FLAGS = -c -Wall -fprofile-arcs -ftest-coverage -I $(GOOGLE_TEST_INCLUDE)
LD_FLAGS = -L /usr/local/lib -l $(GOOGLE_TEST_LIB) -l pthread -lgcov

OBJECTS = arvore.o
OBJECTSGCOV = arvoretest.gcno arvoretest.gcda
TARGET = arvoretest.cpp arvore.cpp

all: $(TARGET)

$(TARGET): $(OBJECTS)
	g++ $(TARGET) -o $(OBJECTS) $(LD_FLAGS)

%.o : %.cpp
	$(G++) $(G++_FLAGS) $<

clean:
	rm -f $(OBJECTS) $(OBJECTSGCOV)

.PHONY: all clean

gcov:
	chmod -R 0755 .
	./$(TARGET)
	gcov $(TARGET) -m

