#ifndef VOITURE_H
#define VOITURE_H
#include <string>
#include "Modele.h"
#include "Option.h"

using namespace std; 

class Voiture
{

	friend Voiture operator+(const Voiture&, const Option&);
	friend Voiture operator+(const Option&, const Voiture&);

	friend Voiture operator-(const Voiture&, const Option&);
	friend Voiture operator-(const Voiture&, string);

	friend ostream& operator<<(ostream&,const Voiture&);

private:
	string nom;
	Modele modele;
	Option* options[5] = {NULL};

	int compV(const Voiture&);

public:
	/***** Constructeur/Destructeur *********************/

	Voiture();
	Voiture(const string,const Modele&);
	Voiture(const Voiture&);
	~Voiture();

	/***** Surchargeur **********************************/

	Voiture& operator=(const Voiture&);
	int operator<(const Voiture&);
 	int operator>(const Voiture&);
 	int operator==(const Voiture&);
 	Option* operator[](int);


	/***** Setteur/Getteur ******************************/

	void setNom(const string);
	string getNom()const;

	void setModele(const Modele&);
	Modele getModele()const;

	/***** Methode Publique *****************************/

	void AjouteOption(const Option&);
	void RetireOption(string);
	float getPrix()const;
	void Affiche()const;
};



#endif