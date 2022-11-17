#include "Employe.h"


string Employe::ADMINISTRATIF ="Administratif" ;
string Employe::VENDEUR ="Vendeur" ;

/**********************************************************************************************************/
/***************** Constructeur/Destructeur ***************************************************************/
/**********************************************************************************************************/

Employe :: Employe(): Intervenant()
{
	#ifdef DEBUG
		cout << "Constructeur par defaut de Employe" << endl;
	#endif

	setLogin("pas de login");
	setFonction("pas de fonction");
}


Employe :: Employe(string nom,string pers,int numero, string log, string fonct): Intervenant(nom,pers,numero)
{
	#ifdef DEBUG
		cout << "Constructeur d'initialisation Employe" << log << endl;
	#endif

	setLogin(log);
	setFonction(fonct);
}

Employe :: Employe(const Employe& emp): Intervenant(emp)
{
	#ifdef DEBUG
		cout << "Constructeur de copie Employe " << endl;
	#endif

	setLogin(emp.getLogin());
	setFonction(emp.getFonction());
	setMotDePasse(emp.getMotDePasse());
}

Employe::~Employe()
{
	#ifdef DEBUG
		cout << "Destructeur de Employe "<< endl;
	#endif

	if(motDePasse)
		ResetMotDePasse(motDePasse);
}

/**********************************************************************************************************/
/***************** Surchargeur ****************************************************************************/
/**********************************************************************************************************/

Employe& Employe::operator=(const Employe& emp)
{
	setNom(emp.getNom());
	setPrenom(emp.getPrenom());
	setNumero(emp.getNumero());
	setLogin(emp.getLogin());
	setFonction(emp.getFonction());
	setMotDePasse(emp.getMotDePasse());

	return (*this);
}

ostream& operator<<(ostream& s,const Employe& emp)
{
	//s << o.getCode() << "/" << o.getIntitule() << "/" << o.getPrix() << "€";
	s << endl << "\tNom: "<< emp.getNom() << endl << "\tPrenom: " << emp.getPrenom() << endl;
	s << "\tNumero: "<< emp.getNumero() << endl << "\tLogin: " << emp.getLogin() << endl;
	s << "\tFonction: "<< emp.getFonction() << endl;

	return s;
}

/**********************************************************************************************************/
/***************** Setteur/Getteur ************************************************************************/
/**********************************************************************************************************/

void Employe::setLogin(string n){ login = n; }
string Employe::getLogin()const{ return login; }

	
void Employe::setMotDePasse(string n){

	int i;
	int len = n.length();

	if(len < 6)
		throw PasswordException(1,"INVALID_LENGTH");

	for (i = 0; i < len && !isalpha(n[i]); i++);
	if(i == len)
		throw PasswordException(2,"ALPHA_MISSING");

	for (i = 0; i < len && !isdigit(n[i]); i++);
	if(i == len)
		throw PasswordException(3,"DIGIT_MISSING");

	motDePasse= new string(n);
}


string Employe::getMotDePasse()const{
	if(motDePasse == NULL)
		throw PasswordException(4,"NO_PASSWORD");

	return *motDePasse;
}


void Employe::ResetMotDePasse(string*motDePasse){
	if(motDePasse)
		delete motDePasse;
	motDePasse=NULL;
}

int Employe::setFonction(string n){
	if(n!="Vendeur" && n!="Administratif" && n!="pas de fonction")
		return 0;
	fonction = n;
	return 1;
}
string Employe::getFonction()const{return fonction;}

/**********************************************************************************************************/
/***************** Methode Vietuelle **********************************************************************/
/**********************************************************************************************************/

string Employe::ToString()const{
	string s,s1;

	if(fonction == "Vendeur")
		s1 = string("[V");
	else if(fonction == "Administratif")
		s1 = string("[A");

	s= s1 + to_string(getNumero()) + string("] ") + getNom() + string(" ") + getPrenom();
	return s;
}


string Employe::Tuple()const{
	string s;
	s= to_string(getNumero()) + string(";") + getNom() + string(";") + getPrenom() + string(";") + getFonction();
	return s;
}

