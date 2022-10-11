#include "Modele.h"

#include <iostream>
#include <string.h>

using namespace std;

/**********************************************************************************************************/
/***************** Constructeur/Destructeur ***************************************************************/
/**********************************************************************************************************/

Modele :: Modele()
{
	#ifdef DEBUG
		cout << "Constructeur par defaut de Modele" << endl;
	#endif

	puissance=0;
	prixDeBase=0;
	moteur=Essence;
	setNom("Modele sans nom");
}


Modele :: Modele(string n,int p,Moteur mot,float PDB)
{
	#ifdef DEBUG
		cout << "Constructeur d'initialisation" << n << " " << p << " " << mot << " " << PDB <<endl;
	#endif

	puissance=p;
	prixDeBase=PDB;
	moteur=mot;
	nom=n;
}

Modele :: Modele(const Modele& Mod)
{
	#ifdef DEBUG
		cout << "Constructeur de copie" << Mod.getNom() << " " << Mod.getPuissance() << " " << Mod.getMoteur() << " " << Mod.getPrixDeBase() <<endl;
	#endif

	puissance=Mod.puissance;
	prixDeBase=Mod.prixDeBase;
	moteur=Mod.moteur;
	nom=Mod.nom;
}

Modele::~Modele()
{
	#ifdef DEBUG
		cout << "Destructeur de Modele" <<endl;
	#endif
}

/**********************************************************************************************************/
/***************** Setteur/Getteur ************************************************************************/
/**********************************************************************************************************/

void Modele::setNom(string n){ nom=n; }

string Modele::getNom()const{ return nom; }

void Modele::setPuissance(int p){ puissance=p; }
int Modele::getPuissance()const{ return puissance; }

void Modele::setPrixDeBase(float PDB){ prixDeBase=PDB; }	
float Modele::getPrixDeBase()const{ return prixDeBase; }

void Modele::setMoteur(Moteur mot){ moteur=mot; }	
Moteur Modele::getMoteur()const{ return moteur; }

/**********************************************************************************************************/
/***************** Methode Publique ***********************************************************************/
/**********************************************************************************************************/

void Modele::Affiche()const
{
	cout<<endl<<"Nom: "<<nom<<endl;
	cout<<"Puissance: "<<puissance<<"ch"<<endl;
	cout<<"Prix de base: "<<prixDeBase<<"€"<<endl;
	cout<<"Moteur: ";

	switch(moteur)
	{
		case Essence:
			cout<<"Essence"<<endl<<endl;
			break;
		case Diesel:
			cout<<"Diesel"<<endl<<endl;
			break;
		case Electrique:
			cout<<"Electrique"<<endl<<endl;
			break;
		case Hybride:
			cout<<"Hybride"<<endl<<endl;
			break;
	}
}