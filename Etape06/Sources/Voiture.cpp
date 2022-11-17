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

	setNom("Voiture sans nom");
}


Voiture :: Voiture(string n,const Modele& mod)
{
	#ifdef DEBUG
		cout << "Constructeur d'initialisation Voiture " << n << endl;
	#endif

	setNom(n);
	setModele(mod);
}

Voiture :: Voiture(const Voiture& vhl)
{
	#ifdef DEBUG
		cout << "Constructeur de copie Voiture " << vhl.getNom() << endl;
	#endif

	setNom(vhl.getNom());
	setModele(vhl.getModele());

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
/***************** Surchargeur ****************************************************************************/
/**********************************************************************************************************/

Voiture& Voiture::operator=(const Voiture& V)
{
	for(int i=0;i<5;i++){
		if(options[i]!= NULL){
			delete options[i];
			options[i]=NULL;
		}	
	}

	setNom(V.getNom());
	setModele(V.getModele());

	for(int i=0;i<5;i++){
		if(V.options[i]!= NULL){
			options[i] = new Option(*V.options[i]);
		}
	}
	return (*this);
}

Voiture operator+(const Voiture& V, const Option& option)
{
	Voiture V1(V);

	V1.AjouteOption(option);

	return V1;
}
Voiture operator+(const Option & option,const Voiture& V){	return V + option;}

Voiture operator-(const Voiture& V, const Option & option)
{
	#ifdef DEBUG
		cout << "operator- option " << endl;
	#endif

	Voiture V1(V);

	V1.RetireOption(option.getCode());

	return V1;
}

Voiture operator-(const Voiture& V, string n)
{
	#ifdef DEBUG
		cout << "operator- string" << endl;
	#endif

	Voiture V1(V);

	V1.RetireOption(n);

	return V1;
}

int Voiture::operator<(const Voiture& V)
{
 	return compV(V)==-1;
}
int Voiture::operator>(const Voiture& V)
{
 	return compV(V)==1;
}
int Voiture::operator==(const Voiture& V)
{
 	return compV(V)==0;
}

int Voiture::compV(const Voiture& V)
{
	 if (getPrix() < V.getPrix()) return -1;
	 if (getPrix() > V.getPrix()) return 1;
	 return 0;
}

ostream& operator<<(ostream& s,const Voiture& V)
{
	s<<endl<<"Nom Projet: "<< V.getNom() << endl << endl;
	s<< "Modele: " << V.getModele() << endl;

	int j=0;
	s<<"Option(s): "<< endl;
	for(int i=0;i<5;i++){
		if (V.options[i]!= NULL){
			s << endl << "-" << j+1 << ": ";
			s << *(V.options[i]);
			j++;
		}
	}

	return s;
}

Option* Voiture::operator[](int i){
	return options[i];
}

/**********************************************************************************************************/
/***************** Setteur/Getteur ************************************************************************/
/**********************************************************************************************************/

void Voiture::setNom(string n){ nom = n; }
string Voiture::getNom()const{ return nom; }

void Voiture::setModele(const Modele& mod){
	modele.setNom(mod.getNom());
	modele.setPuissance(mod.getPuissance());
	modele.setMoteur(mod.getMoteur());
	modele.setPrixDeBase(mod.getPrixDeBase());
}
Modele Voiture::getModele()const{ return modele; }

/**********************************************************************************************************/
/***************** Methode Publique ***********************************************************************/
/**********************************************************************************************************/

void Voiture::AjouteOption(const Option & option){
	int i;

	for(i=0;i<5 && options[i]!= NULL && options[i]->getCode() != option.getCode();i++);
	
	if (i<5 && options[i] == NULL)
		options[i] = new Option(option);
	else if(i<5 && options[i]->getCode() == option.getCode())
			throw OptionException("L\'option est deja presente dans la voiture");
	else if(i == 5 && options[i-1]!= NULL)
		throw OptionException("La voiture contient deja 5 options");
}

void Voiture::RetireOption(string n){
	int i;
	string test;
	for(i=0;i<5 && test!=n;i++)
	{
		if(options[i] != NULL){
			test=options[i]->getCode();
		}

	}

	if(test == n){
		delete options[i-1];
		options[i-1]=NULL;
	}
	else
		throw OptionException("L\'option n\'est pas presente");

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