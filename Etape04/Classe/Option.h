#ifndef OPTION_H
#define OPTION_H
#include <string>

using namespace std; 

class Option
{
	friend ostream& operator<<(ostream&,const Option&);
	friend istream& operator>>(istream&,Option&);


private:
	string code;
	string intitule;
	float prix;

public:
	Option();
	Option(string,string,float);
	Option(const Option&);
	~Option();

	Option operator--();
	Option operator--(int);


	void setCode(string);
	string getCode()const;

	void setIntitule(string);
	string getIntitule()const;

	void setPrix(float);
	float getPrix()const;

	void Affiche()const;
};



#endif