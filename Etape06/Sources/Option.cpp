#include "Option.h"

/**********************************************************************************************************/
/***************** Constructeur/Destructeur ***************************************************************/
/**********************************************************************************************************/

Option :: Option()
{
	#ifdef DEBUG
		cout << "Constructeur par defaut de Option" << endl;
	#endif

	setCode("0000");
	setIntitule("Pas d intitule");
	setPrix(0);
}


Option :: Option(string c,string i,float p)
{
	#ifdef DEBUG
		cout << "Constructeur d'initialisation Option" << c << " " << i << " " << p << endl;
	#endif

	setCode(c);
	setIntitule(i);
	setPrix(p);
}

Option :: Option(const Option& opt)
{
	#ifdef DEBUG
		cout << "Constructeur de copie Option " << opt.getCode() << " " << opt.getIntitule() << " " << opt.getPrix() << endl;
	#endif

	setCode(opt.code);
	setIntitule(opt.intitule);
	setPrix(opt.prix);
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

void Option::setCode(string n)
{
	if(n.length() != 4) {
		throw OptionException("Le code d\'une option doit comporter exatement 4 caracteres");
	}
	code = n;
}
string Option::getCode()const{ return code; }

void Option::setIntitule(string n)
{ 
	if(n.length() == 0) {
		throw OptionException("L\'intitule d\'une option ne peut etre vide");
	}
	intitule = n; 
}
string Option::getIntitule()const{ return intitule; }

void Option::setPrix(float p)
{ 
	if(!cin) {
		cin.clear();
		cin.ignore(10000, '\n');
		throw OptionException("Le prix d\'une option doit etre un nombre");
	}
	else if(p < 0)
		throw OptionException("Le prix d\'une option doit etre positif ou nul");
	prix=p; 
}
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