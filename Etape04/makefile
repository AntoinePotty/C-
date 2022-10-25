CLASSE = Classe/
OBJS = Classe/Modele.o Classe/Voiture.o Classe/Option.o Classe/Personne.o Classe/Intervenant.o Classe/Client.o Classe/Employe.o
CO = g++ -I $(CLASSE)
DEBUG =	#-D DEBUG
TEST =	Test4

$(TEST):	$(TEST).cpp $(CLASSE)Modele.o $(CLASSE)Voiture.o $(CLASSE)Option.o $(CLASSE)Personne.o $(CLASSE)Intervenant.o $(CLASSE)Client.o $(CLASSE)Employe.o
	$(CO) $(OBJS) $(TEST).cpp $(DEBUG) -o $(TEST)

Classe/Voiture.o:	$(CLASSE)Voiture.h $(CLASSE)Voiture.cpp
	g++ $(CLASSE)Voiture.cpp $(DEBUG) -c -o $(CLASSE)Voiture.o

Classe/Modele.o:	$(CLASSE)Modele.h $(CLASSE)Modele.cpp
	g++ $(CLASSE)Modele.cpp $(DEBUG) -c -o $(CLASSE)Modele.o

Classe/Option.o:	$(CLASSE)Option.h $(CLASSE)Option.cpp
	g++ $(CLASSE)Option.cpp $(DEBUG) -c -o $(CLASSE)Option.o

Classe/Personne.o:	$(CLASSE)Personne.h $(CLASSE)Personne.cpp
	g++ $(CLASSE)Personne.cpp $(DEBUG) -c -o $(CLASSE)Personne.o

Classe/Intervenant.o:	$(CLASSE)Intervenant.h $(CLASSE)Intervenant.cpp
	g++ $(CLASSE)Intervenant.cpp $(DEBUG) -c -o $(CLASSE)Intervenant.o

Classe/Client.o:	$(CLASSE)Client.h $(CLASSE)Client.cpp
	g++ $(CLASSE)Client.cpp $(DEBUG) -c -o $(CLASSE)Client.o

Classe/Employe.o:	$(CLASSE)Employe.h $(CLASSE)Employe.cpp
	g++ $(CLASSE)Employe.cpp $(DEBUG) -c -o $(CLASSE)Employe.o

Clean:
	rm $(CLASSE)*.o