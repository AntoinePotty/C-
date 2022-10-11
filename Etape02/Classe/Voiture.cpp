#include "Voiture.h"
#include "Modele.h"
#include "Option.h"

#include <iostream>
#include <string.h>

using namespace std;

/**********************************************************************************************************/
/***************** Constructeur/Destructeur ***************************************************************/
/**********************************************************************************************************/

Voiture :: Voiture()
{
	#ifdef DEBUG
		cout << "Constructeur par defaut de Voiture" << endl;
	#endif

	nom="Voiture sans nom";
}


Voiture :: Voiture(const string n,const Modele mod)
{
	#ifdef DEBUG
		cout << "Constructeur d'initialisation Voiture " << n << endl;
	#endif

	nom=n;
	modele=mod;
}

Voiture :: Voiture(const Voiture& vhl)
{
	#ifdef DEBUG
		cout << "Constructeur de copie Voiture " << vhl.getNom() << endl;
	#endif

	nom = vhl.nom;
	modele = vhl.modele;

	for(int i=0;i<5;i++){
		if(vhl.options[i]!= NULL)
			options[i] = new Option(*vhl.options[i]);
	}
}

Voiture::~Voiture()
{
	#ifdef DEBUG
		cout << "Destructeur de Voiture " << endl;
	#endif

	for(int i=0;i<5;i++){
		if(options[i]!= NULL){
			delete options[i];
			options[i]=NULL;
		}	
	}
}

/**********************************************************************************************************/
/***************** Setteur/Getteur ************************************************************************/
/**********************************************************************************************************/

void Voiture::setNom(const string n){ nom = n; }
string Voiture::getNom()const{ return nom; }

void Voiture::setModele(const Modele mod){ modele=mod; }
Modele Voiture::getModele()const{ return modele; }

/**********************************************************************************************************/
/***************** Methode Publique ***********************************************************************/
/**********************************************************************************************************/

void Voiture::AjouteOption(const Option & option){
	int i;

	for(i=0;i<5 && options[i]!= NULL;i++);

	if(options[i] == NULL){
		options[i] = new Option(option);
	}
	else
		cout << "Plus de Place dans le tableau" <<endl;
}

void Voiture::RetireOption(const string n){
	int i;
	for(i=0;i<5 && options[i]->getCode() != n ;i++);

	if(i<5){
		delete options[i];
		options[i]=NULL;
	}
}

float Voiture::getPrix()const{
	float Prix = modele.getPrixDeBase();

	for(int i=0;i<5;i++){
		if(options[i]!= NULL)
			Prix = Prix + options[i]->getPrix();
	}
	return Prix;
}

void Voiture::Affiche()const
{
	cout<<endl<<"Nom Projet: "<< getNom();
	modele.Affiche();

	int j=0;
	cout<<"Option(s): "<< endl << endl;
	for(int i=0;i<5;i++){
		if (options[i]!= NULL){
			cout<< j+1 << ": ";
			options[i]->Affiche();
			j++;
		}
	}
}