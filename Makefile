CC = g++
CCFLAGS = -Wall  
LIBFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
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

recompile: clean all
	./ZomBee
	
clean:
	rm -f $(OBJ) ZomBee