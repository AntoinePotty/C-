CC = g++
EXEC = Test6
DEBUG = #-D DEBUG

Fichier.cpp = Sources/
Fichier.o = Objets/
Fichier.h = H/

SRC = $(wildcard $(Fichier.cpp)*.cpp)
TMP = $(SRC:$(Fichier.cpp)%=$(Fichier.o)%)
OBJ = $(TMP:.cpp=.o)


all : $(EXEC)

$(Fichier.o)%.o :	$(Fichier.cpp)%.cpp
	$(CC) -o $@ -c $< $(DEBUG) -I $(Fichier.h)


$(EXEC) :	$(OBJ) $(EXEC).cpp
	$(CC) -o $@ $(OBJ) $(EXEC).cpp $(DEBUG) -I $(Fichier.o) -I $(Fichier.h)


Clean:
	rm $(Fichier.o)*.o