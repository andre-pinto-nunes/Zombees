CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
LIBFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SRC= $(wildcard ../*.cc)
OBJ= $(SRC:.cc=.o)
TST= $(wildcard *.cc)
OBJ_TEST = $(filter-out ../main.o, $(OBJ)) $(TST:.cc=.o)

ifeq ($(OS),Windows_NT)
	EXEC= testcase.exe
else
	EXEC= testcase
endif 

testcase : $(OBJ_TEST) 
	$(CC) $(CCFLAGS) -o  $@ $^ $(LIBFLAGS)
	mv $(EXEC) ../							# deplace l'executable pour qu'il n'y ait par d'erreur d'ouverture de fichier

%.o: %.cc
	$(CC) $(CCFLAGS) -I../ -o $@ -c $<

clean :
	rm -f $(OBJ_TEST)
	cd ../ ; rm -f $(OBJ_TEST) $(EXEC)
