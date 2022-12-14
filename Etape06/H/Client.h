#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include "Intervenant.h"

using namespace std; 

class Client : public Intervenant
{
	friend ostream& operator<<(ostream&,const Client&);
private:
	int compV(const Client&);
protected:
	string gsm;

public:
	Client();
	Client(string,string,int,string);
	Client(const Client&);
	~Client();

	Client& operator=(Client&);

	int operator<(const Client&);
 	int operator>(const Client&);
 	int operator==(const Client&);

	string ToString()const;
	string Tuple()const;

	void setGsm(string);
	string getGsm()const;
};
#endif