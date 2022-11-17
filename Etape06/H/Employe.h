#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <string>
#include <iostream>

#include "Employe.h"
#include "Intervenant.h"
#include "PasswordException.h"

using namespace std; 

class Employe : public Intervenant
{
	friend ostream& operator<<(ostream&,const Employe&);

protected:
	string login;
	string* motDePasse = NULL;
	string fonction;


public:
	static string ADMINISTRATIF;
	static string VENDEUR;

	Employe();
	Employe(string,string,int,string,string);
	Employe(const Employe&);
	~Employe();

	Employe& operator=(const Employe&);

	string ToString()const;
	string Tuple()const;

	void setLogin(string);
	string getLogin()const;

	void setMotDePasse(string);
	string getMotDePasse()const;
	void ResetMotDePasse(string*);

	int setFonction(string);
	string getFonction()const;
};
#endif