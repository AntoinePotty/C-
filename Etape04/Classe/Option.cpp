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


Option :: Option(string c,string i,float p)
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
		cout << "Destructeur de Option " << getCode() << endl;
	#endif
}

/**********************************************************************************************************/
/***************** Surchargeur ****************************************************************************/
/**********************************************************************************************************/

ostream& operator<<(ostream& s,const Option& o)
{
	//s << o.getCode() << "/" << o.getIntitule() << "/" << o.getPrix() << "€";
	s << endl << "\tCode: "<< o.getCode() << endl << "\tIntitule: " << o.getIntitule() << endl << "\tPrix: "<< o.getPrix() << endl;
	return s;
}

istream& operator>>(istream& s,Option& o)
{
	string code,intitule;
	float prix;

	cout << "Code: ";
	cin >> code;
	cout << "Intitule: ";
	cin >> intitule;
	cout << "Prix: ";
	cin.clear();
	cin >> prix;

	o.setCode(code);
	o.setIntitule(intitule);
	o.setPrix(prix);

	return s;
}

Option Option::operator--(){
	setPrix(getPrix() - 50);
	 return (*this);
}

Option Option::operator--(int){
	Option temp(*this);
	setPrix(getPrix() - 50);
	 return temp;
}
/**********************************************************************************************************/
/***************** Setteur/Getteur ************************************************************************/
/**********************************************************************************************************/

void Option::setCode(string n){ code = n; }
string Option::getCode()const{ return code; }

void Option::setIntitule(string n){ intitule = n; }
string Option::getIntitule()const{ return intitule; }

void Option::setPrix(float p){ prix=p; }
float Option::getPrix()const{ return prix; }

/**********************************************************************************************************/
/***************** Methode Publique ***********************************************************************/
/**********************************************************************************************************/

void Option::Affiche()const
{
	cout<<endl<<"Code: "<< getCode() << endl;
	cout<<"Intitule: "<< getIntitule() << endl;
	cout<<"Prix: "<< getPrix() << "€" << endl << endl;
}