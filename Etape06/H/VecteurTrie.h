#ifndef VECTEURTRIE_H
#define VECTEURTRIE_H

#include <iostream>
#include "Iterateur.h"
#include "Vecteur.h"

using namespace std; 

template<class T> class Iterateur;

template<class T> 
class VecteurTrie : public Vecteur<T>
{
public :
    VecteurTrie();
    VecteurTrie(int);
    VecteurTrie(const VecteurTrie<T>&);
    ~VecteurTrie();

    void insere(const T & val);
};

template class VecteurTrie<int>;
#include "Client.h"
template class VecteurTrie<Client>;

#endif