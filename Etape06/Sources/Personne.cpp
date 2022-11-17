#include "Personne.h"

#include <iostream>

using namespace std;

/**********************************************************************************************************/
/***************** Constructeur/Destructeur ***************************************************************/
/**********************************************************************************************************/

Personne :: Personne()
{
	#ifdef DEBUG
		cout << "Constructeur par defaut de Personne" << endl;
	#endif

	nom="Pas de nom";
	prenom="Pas de prenom";
}


Personne :: Personne(string n,string p)
{
	#ifdef DEBUG
		cout << "Constructeur d'initialisation Personne" << n << " " << p << endl;
	#endif

	nom=n;
	prenom=p;
}

Personne :: Personne(const Personne& pers)
{
	#ifdef DEBUG
		cout << "Constructeur de copie Personne " << pers.getNom() << " " << pers.getPrenom() << endl;
	#endif

	nom=pers.getNom();
	prenom=pers.getPrenom();
}

Personne::~Personne()
{
	#ifdef DEBUG
		cout << "Destructeur de Personne " << getNom() << getPrenom() << endl;
	#endif
}

/**********************************************************************************************************/
/***************** Surchargeur ****************************************************************************/
/**********************************************************************************************************/

Personne& Personne::operator=(const Personne& p)
{
	setNom(p.getNom());
	setPrenom(p.getPrenom());

	return (*this);
}

ostream& operator<<(ostream& s,const Personne& p)
{
	//s << o.getCode() << "/" << o.getIntitule() << "/" << o.getPrix() << "€";
	s << endl << "\tNom: "<< p.getNom() << endl << "\tPrenom: " << p.getPrenom() << endl;
	return s;
}

istream& operator>>(istream& s,Personne& p)
{
	string nom,prenom;

	cin.clear();
	cout << "Nom: ";
	cin >> nom;
	cout << "Prenom: ";
	cin >> prenom;

	p.setNom(nom);
	p.setPrenom(prenom);

	return s;
}
/**********************************************************************************************************/
/***************** Setteur/Getteur ************************************************************************/
/**********************************************************************************************************/

void Personne::setNom(string n){ nom = n; }
string Personne::getNom()const{ return nom; }

void Personne::setPrenom(string n){ prenom = n; }
string Personne::getPrenom()const{ return prenom; }

/**********************************************************************************************************/
/***************** Methode Publique ***********************************************************************/
/**********************************************************************************************************/

void Personne::Affiche()const
{
	cout<<endl<<"Nom: "<< getNom() << endl;
	cout<<"Prenom: "<< getPrenom() << endl << endl;
}