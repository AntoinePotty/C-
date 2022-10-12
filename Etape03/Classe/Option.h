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
	Option(const string,const string,const float);
	Option(const Option&);
	~Option();

	Option operator--();
	Option operator--(int);


	void setCode(const string);
	string getCode()const;

	void setIntitule(const string);
	string getIntitule()const;

	void setPrix(const float);
	float getPrix()const;

	void Affiche()const;
};



#endif