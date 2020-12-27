CC = g++
CCFLAGS = -Wall  
LIBFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ -o ZomBee $(LIBFLAGS)  

%.o: %.cc
	$(CC) $(CCFLAGS) -c $<

.depend:
	g++ $(CCFLAGS) -MM $(SRC) > .depends
-include .depends

clean:
	rm -f $(OBJ) ZomBee