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

	setPuissance(Mod.getPuissance());
	setPrixDeBase(Mod.getPrixDeBase());
	setMoteur(Mod.getMoteur());
	setNom(Mod.getNom());
}

Modele::~Modele()
{
	#ifdef DEBUG
		cout << "Destructeur de Modele" <<endl;
	#endif
}

/**********************************************************************************************************/
/***************** Surchargeur ****************************************************************************/
/**********************************************************************************************************/

Modele& Modele::operator=(const Modele& mod)
{
	#ifdef DEBUG
		cout << "Operateur =" <<endl;
	#endif

	setPuissance(mod.getPuissance());
	setPrixDeBase(mod.getPrixDeBase());
	setMoteur(mod.getMoteur());
	setNom(mod.getNom());

	return (*this);
}


ostream& operator<<(ostream& s,const Modele& m)
{
	//s << o.getCode() << "/" << o.getIntitule() << "/" << o.getPrix() << "€";
	s<<endl<<"\tNom: "<<m.getNom()<< endl <<"\tPuissance: "<<m.getPuissance()<<"ch"<< endl<<"\tPrix de base: "<<m.getPrixDeBase()<<"€"<<endl<<"\tMoteur: ";

	switch(m.getMoteur())
	{
		case Essence:
			s<<"Essence"<<endl;
			break;
		case Diesel:
			s<<"Diesel"<<endl;
			break;
		case Electrique:
			s<<"Electrique"<<endl;
			break;
		case Hybride:
			s<<"Hybride"<<endl;
			break;
	}return s;
}

istream& operator>>(istream& s,Modele& m)
{
	string nom;
	int puissance,i;
	Moteur moteur;
	float prixDeBase;

	cout << "Nom: ";
	cin >> nom;
	cin.clear();
	cout << "Puissance: ";
	cin >> puissance;
	cout << "Moteur (1.Essence/2.Diesel/3.Electrique/4.Hybride): ";
	cin.clear();
	cin >> i;
	switch(i)
	{
		case 1:
			moteur = Essence;
			break;
		case 2:
			moteur = Diesel;
			break;
		case 3:
			moteur = Electrique;
			break;
		case 4:
			moteur = Hybride;
			break;
	}

	cout << "Prix de Base: ";
	cin.clear();
	cin >> prixDeBase;

	m.setNom(nom);
	m.setPuissance(puissance);
	m.setMoteur(moteur);
	m.setPrixDeBase(prixDeBase);

	return s;
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