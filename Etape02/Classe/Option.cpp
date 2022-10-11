#include "Option.h"

#include <iostream>
#include <string.h>

using namespace std;

/**********************************************************************************************************/
/***************** Constructeur/Destructeur ***************************************************************/
/**********************************************************************************************************/

Option :: Option()
{
	#ifdef DEBUG
		cout << "Constructeur par defaut de Option" << endl;
	#endif

	code="0000";
	intitule="Pas d intitule";
	prix=0;
}


Option :: Option(const string c,const string i,const float p)
{
	#ifdef DEBUG
		cout << "Constructeur d'initialisation Option" << c << " " << i << " " << p << endl;
	#endif

	code=c;
	intitule=i;
	prix=p;
}

Option :: Option(const Option& opt)
{
	#ifdef DEBUG
		cout << "Constructeur de copie Option " << opt.getCode() << " " << opt.getIntitule() << " " << opt.getPrix() << endl;
	#endif

	code=opt.code;
	intitule=opt.intitule;
	prix=opt.prix;
}

Option::~Option()
{
	#ifdef DEBUG
		cout << "Destructeur de Option" << endl;
	#endif
}

/**********************************************************************************************************/
/***************** Setteur/Getteur ************************************************************************/
/**********************************************************************************************************/

void Option::setCode(const string n){ code = n; }
string Option::getCode()const{ return code; }

void Option::setIntitule(const string n){ intitule = n; }
string Option::getIntitule()const{ return intitule; }

void Option::setPrix(const float p){ prix=p; }
float Option::getPrix()const{ return prix; }

/**********************************************************************************************************/
/***************** Methode Publique ***********************************************************************/
/**********************************************************************************************************/

void Option::Affiche()const
{
	cout<<endl<<"Code: "<< getCode() << endl;
	cout<<"Intitule: "<< getIntitule() << endl;
	cout<<"Prix: "<< getPrix() << endl << endl;
}