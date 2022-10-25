#include "Intervenant.h"

#include <iostream>

using namespace std;

/**********************************************************************************************************/
/***************** Constructeur/Destructeur ***************************************************************/
/**********************************************************************************************************/

Intervenant :: Intervenant(): Personne()
{
	#ifdef DEBUG
		cout << "Constructeur par defaut de Intervenant" << endl;
	#endif

	numero=0;
}


Intervenant :: Intervenant(string nom,string pers,int num): Personne(nom,pers)
{
	#ifdef DEBUG
		cout << "Constructeur d'initialisation Intervenant" << num << endl;
	#endif

	setNumero(num);
}

Intervenant :: Intervenant(const Intervenant& Int): Personne(Int)
{
	#ifdef DEBUG
		cout << "Constructeur de copie Intervenant " << Int.getNumero() << endl;
	#endif

	setNumero(Int.getNumero());
}

Intervenant::~Intervenant()
{

	#ifdef DEBUG
		cout << "Destructeur de Intervenant " << getNumero() << endl;
	#endif
}

/**********************************************************************************************************/
/***************** Surchargeur ****************************************************************************/
/**********************************************************************************************************/

Intervenant& Intervenant::operator=(const Intervenant& i)
{
	setNom(i.getNom());
	setPrenom(i.getPrenom());
	setNumero(i.getNumero());

	return (*this);
}
/**********************************************************************************************************/
/***************** Setteur/Getteur ************************************************************************/
/**********************************************************************************************************/

void Intervenant::setNumero(int n){ numero = n; }
int Intervenant::getNumero()const{ return numero; }

/**********************************************************************************************************/
/***************** Methode Virtuel ************************************************************************/
/**********************************************************************************************************/
