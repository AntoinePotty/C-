#include "Client.h"
#include "Intervenant.h"


#include <iostream>

using namespace std;

/**********************************************************************************************************/
/***************** Constructeur/Destructeur ***************************************************************/
/**********************************************************************************************************/

Client :: Client(): Intervenant()
{
	#ifdef DEBUG
		cout << "Constructeur par defaut de Client" << endl;
	#endif

	gsm="pas de num";
}


Client :: Client(string nom,string pers,int numero, string g): Intervenant(nom,pers,numero)
{
	#ifdef DEBUG
		cout << "Constructeur d'initialisation Client" << numero << endl;
	#endif

	gsm = g;

}

Client :: Client(const Client& cli): Intervenant(cli)
{
	#ifdef DEBUG
		cout << "Constructeur de copie Client " << cli.getGsm() << endl;
	#endif

	gsm = cli.getGsm();
}

Client::~Client()
{
	#ifdef DEBUG
		cout << "Destructeur de Client "<< endl;
	#endif
}

/**********************************************************************************************************/
/***************** Surchargeur ****************************************************************************/
/**********************************************************************************************************/

Client& Client::operator=(const Client& cli)
{
	setNom(cli.getNom());
	setPrenom(cli.getPrenom());
	setNumero(cli.getNumero());
	setGsm(cli.getGsm());

	return (*this);
}

ostream& operator<<(ostream& s,const Client& cli)
{
	//s << o.getCode() << "/" << o.getIntitule() << "/" << o.getPrix() << "€";
	s << endl << "\tNom: "<< cli.getNom() << endl << "\tPrenom: " << cli.getPrenom() << endl;
	s << "\tNumero: "<< cli.getNumero() << endl << "\tGsm: " << cli.getGsm() << endl;

	return s;
}

/**********************************************************************************************************/
/***************** Setteur/Getteur ************************************************************************/
/**********************************************************************************************************/

void Client::setGsm(string n){ gsm = n; }
string Client::getGsm()const{ return gsm; }

/**********************************************************************************************************/
/***************** Methode Vietuelle **********************************************************************/
/**********************************************************************************************************/

string Client::ToString()const{
	string C="[C";
	string

	s= string("[C") + to_string(getNumero()) + string("] ") + getNom() + string(" ") + getPrenom();
	return s;
}


string Client::Tuple()const{
	string s;
	s= to_string(getNumero()) + string(";") + getNom() + string(";") + getPrenom() + string(";") + getGsm();
	return s;
}

