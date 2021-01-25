CC = g++
CCFLAGS = -Wall -Werror
LIBFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)
TST_DIR=tests/
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ -o ZomBee $(LIBFLAGS)  

%.o: %.cc
	$(CC) $(CCFLAGS) -c $<

testcase : 
	cd $(TST_DIR) ;  make

.depend:
	g++ $(CCFLAGS) -MM $(SRC) > .depends
-include .depends

recompile: clean all
	./ZomBee
	
clean:
	rm -f $(OBJ) ZomBee
	cd $(TST_DIR) ; make clean