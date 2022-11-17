#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>
#include <iostream>

using namespace std;

class Exception
{
 private:
    string message;

 public:
    Exception(string m){
        #ifdef DEBUG
            cout << "Constructeur copie Exception" << endl;
        #endif
        message = m;
    }
    ~Exception() {
        #ifdef DEBUG
            cout << "Destructeur Exception" << endl;
        #endif
    }

    string getMessage() const { return message; }

};

#endif