#ifndef OPTIONEXCEPTION_H
#define OPTIONEXCEPTION_H
#include <string>
#include <iostream>
#include "Exception.h"

using namespace std;

class OptionException : public Exception
{
 public:
    OptionException(string e) : Exception(e) 
    {
      #ifdef DEBUG
        cout << "Constructeur copie OptionException" << endl;
      #endif
    }

   ~OptionException() {
      #ifdef DEBUG
        cout << "Destructeur OptionException" << endl;
      #endif
    }
};

#endif