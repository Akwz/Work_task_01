CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp figure.cpp point.cpp interval.cpp line.cpp area.cpp filter_manager.cpp calc_method.cpp algorithms.cpp ratio.cpp range.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=app

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)