#ifndef ITERATEUR_H
#define ITERATEUR_H

#include <iostream>
#include "Vecteur.h"

using namespace std;

template<class T> class Vecteur;

template<class T> class Iterateur
{

private:
    Vecteur<T>& vecteur;
    T *p;

public:
    Iterateur(Vecteur<T>& vec) : vecteur(vec), p(vecteur.v){};

    bool end() const // Détecte la fin du vecteur
    {
        if (p - vecteur.v >= vecteur.size()) return true; // size() ou sizeMax();
        else return false;
    }
    
    void reset() { p = vecteur.v; } // Réinitialize l’itérateur
    bool operator++() // Passe à l’élément suivant
    {
        if (!end())
        {
            p++;
            return true;
        }
        else return false;
    }
    bool operator++ (int) { return operator++(); }
    operator T() const { return *p; } // Renvoie l’élément
};

template class Iterateur<int>;
#include "Client.h"
template class Iterateur<Client>;


#endif