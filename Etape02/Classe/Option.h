#ifndef OPTION_H
#define OPTION_H
#include <string>

using namespace std; 

class Option
{
private:
	string code;
	string intitule;
	float prix;

public:
	Option();
	Option(const string,const string,const float);
	Option(const Option&);
	~Option();


	void setCode(const string);
	string getCode()const;

	void setIntitule(const string);
	string getIntitule()const;

	void setPrix(const float);
	float getPrix()const;

	void Affiche()const;
};



#endif