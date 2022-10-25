#ifndef PERSONNE_H
#define PERSONNE_H
#include <string>

using namespace std; 

class Personne
{
	friend ostream& operator<<(ostream&,const Personne&);
	friend istream& operator>>(istream&,Personne&);

protected:
	string nom;
	string prenom;

public:
	Personne();
	Personne(string,string);
	Personne(const Personne&);
	~Personne();

	Personne& operator=(const Personne&);

	void setNom(string);
	string getNom()const;

	void setPrenom(string);
	string getPrenom()const;

	void Affiche()const;
};
#endif