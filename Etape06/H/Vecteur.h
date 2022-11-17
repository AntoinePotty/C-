#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
#include "Iterateur.h"

using namespace std; 

template<class T> class Iterateur;

template<class T> class Vecteur
{
    
protected :
    T * v;
    int _sizeMax;
    int _size;

public :
    Vecteur();
    Vecteur(int);
    Vecteur(const Vecteur<T>&);
    ~Vecteur();

    int size()const;
    int sizeMax()const;

    void Affiche();

    void insere(const T & val);

    T retire(int ind);

    Vecteur<T> operator=(const Vecteur<T>&);

    T& operator[](int i)const;

    friend class Iterateur<T>;

};

template class Vecteur<int>;
#include "Client.h"
template class Vecteur<Client>;


#endif