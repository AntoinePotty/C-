#ifndef PASSWORDEXCEPTION_H
#define PASSWORDEXCEPTION_H
#include <string>
#include <iostream>
#include "Exception.h"

using namespace std;

class PasswordException : public Exception
{
  private:
    int code;

  public:
    PasswordException(int c, string s) : Exception(s) 
    {
      code = c;
      #ifdef DEBUG
        cout << "Constructeur copie PasswordException" << endl;
      #endif
    }

   ~PasswordException() {
      #ifdef DEBUG
        cout << "Destructeur PasswordException" << endl;
      #endif
    }

    int getCode() const { return code; }
};

#endif