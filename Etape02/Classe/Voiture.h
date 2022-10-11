#ifndef VOITURE_H
#define VOITURE_H
#include <string>
#include "Modele.h"
#include "Option.h"

using namespace std; 

class Voiture
{
private:
	string nom;
	Modele modele;
	Option* options[5] = {NULL};

public:
	/************* Constructeur/Destructeur *************/

	Voiture();
	Voiture(const string,const Modele);
	Voiture(const Voiture&);
	~Voiture();

	/***************** Setteur/Getteur ******************/

	void setNom(const string);
	string getNom()const;

	void setModele(const Modele);
	Modele getModele()const;

	/***************** Methode Publique *****************/

	void AjouteOption(const Option&);
	void RetireOption(const string);
	float getPrix()const;
	void Affiche()const;
};



#endif