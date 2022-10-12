CLASSE = Classe/
OBJS = Classe/Modele.o Classe/Voiture.o Classe/Option.o
CO = g++ -I $(CLASSE)
DEBUG =	#-D DEBUG
TEST =	Test3

$(TEST):	$(TEST).cpp $(CLASSE)Modele.o $(CLASSE)Voiture.o $(CLASSE)Option.o
	$(CO) $(OBJS) $(TEST).cpp $(DEBUG) -o $(TEST)

Classe/Voiture.o:	$(CLASSE)Voiture.h $(CLASSE)Voiture.cpp
	g++ $(CLASSE)Voiture.cpp $(DEBUG) -c -o $(CLASSE)Voiture.o

Classe/Modele.o:	$(CLASSE)Modele.h $(CLASSE)Modele.cpp
	g++ $(CLASSE)Modele.cpp $(DEBUG) -c -o $(CLASSE)Modele.o

Classe/Option.o:	$(CLASSE)Option.h $(CLASSE)Option.cpp
	g++ $(CLASSE)Option.cpp $(DEBUG) -c -o $(CLASSE)Option.o

Clean:
	rm $(CLASSE)*.o