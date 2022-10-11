#ifndef MODELE_H
#define MODELE_H
#include <string>
#include <iostream>

using namespace std; 

enum Moteur { Essence, Diesel, Electrique, Hybride };

class Modele
{
private:
	string nom;
	int puissance;
	Moteur moteur;
	float prixDeBase;

public:
	Modele();
	Modele(string,int,Moteur,float);
	Modele(const Modele&);
	~Modele();

	void setNom(string);
	string getNom()const;

	void setPuissance(int);
	int getPuissance()const;

	void setPrixDeBase(float);
	float getPrixDeBase()const;

	void setMoteur(Moteur);
	Moteur getMoteur()const;


	void Affiche()const;
};



#endif