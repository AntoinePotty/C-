#include "Vecteur.h"
#include "Client.h"

#include <iostream>

using namespace std;

/**********************************************************************************************************/
/***************** Constructeur/Destructeur ***************************************************************/
/**********************************************************************************************************/

template <class T> 
Vecteur<T> :: Vecteur()
{
	#ifdef DEBUG
		cout << "Constructeur par defaut de Vecteur" << endl;
	#endif

	_size = 0;
	_sizeMax = 10;

	v = new T[_sizeMax];
}


template <class T> 
Vecteur<T> :: Vecteur(int max)
{
	#ifdef DEBUG
		cout << "Constructeur d'initialisation Vecteur _sizeMax :" << max <<endl;
	#endif

	_size = 0;
	_sizeMax = max;

	v = new T[_sizeMax];
}

template <class T> 
Vecteur<T> :: Vecteur(const Vecteur<T>& Vec)
{
	#ifdef DEBUG
		cout << "Constructeur de copie Vecteur _sizeMax" << Vec.sizeMax() << "_size" << Vec.size() << endl;
	#endif

	_size = 0;
	_sizeMax = Vec.sizeMax();

	v = new T[_sizeMax];

	for(int i=0 ; i < Vec.size() ; i++){
		insere(Vec[i]);
	}
}

template <class T> 
Vecteur<T> ::~Vecteur()
{
	#ifdef DEBUG
		cout << "Destructeur du Vecteur" <<endl;
	#endif

	delete []v;
}

/**********************************************************************************************************/
/***************** Surchargeur ****************************************************************************/
/**********************************************************************************************************/

template <class T>
Vecteur<T> Vecteur<T>::operator=(const Vecteur<T>& Vec)
{
	#ifdef DEBUG
		cout << "Vecteur::Operateur =" <<endl;
	#endif

	_size = 0;
	_sizeMax = Vec.sizeMax();

	v = new T[_sizeMax];

	for(int i=0 ; i < Vec.size() ; i++){
		insere(Vec[i]);
	}

	return (*this);
}


template <class T>
T& Vecteur<T>::operator[](int i)const
{
	return *(v+i);
}


template <class T>
void Vecteur<T>::insere(const T & val)
{
	#ifdef DEBUG
		cout << "Vecteur<T>::insere =" <<endl;
	#endif
	
	if(size() == sizeMax())
		cout << "Il n'y a pas de place dans le vecteur" << endl;
	else
	{
		v[size()]= val;
	}

	_size++;
}



template <class T>
T Vecteur<T>::retire(int ind)
{
	#ifdef DEBUG
		cout << "Vecteur<T>::retire" <<endl;
	#endif

	T rase;

	int i;

	T ret = v[ind];

	for(i = ind; i < size()-1 ; i++)
	{
		cout << "Vecteur[i]:" << v[i] << "Vecteur[i+1]:" << v[i+1] << endl;
		v[i]= v[i+1];
	}

	v[i] = rase;

	_size--;
	return ret;
}


template <class T>
void Vecteur<T>::Affiche()
{
	#ifdef DEBUG
		cout << "Vecteur<T>::Affiche" << endl;
	#endif

	int i;

	for(i=0; i < size() ; i++)
	{
		cout << "[" << i << "]: " << v[i] << endl;
	}
}


template <class T>
int Vecteur<T>::size()const
{
	return _size;
}
    
template <class T>
int Vecteur<T>::sizeMax()const
{
	return _sizeMax;
}

/**********************************************************************************************************/
/***************** Setteur/Getteur ************************************************************************/
/**********************************************************************************************************/

/*void Modele::setNom(string n){ nom=n; }

string Modele::getNom()const{ return nom; }

void Modele::setPuissance(int p){ puissance=p; }
int Modele::getPuissance()const{ return puissance; }

void Modele::setPrixDeBase(float PDB){ prixDeBase=PDB; }	
float Modele::getPrixDeBase()const{ return prixDeBase; }

void Modele::setMoteur(Moteur mot){ moteur=mot; }	
Moteur Modele::getMoteur()const{ return moteur; }*/

/******************************************************************************************************/
/**************** Methode Publique **********************************************************************/
/**********************************************************************************************************/

/*void Modele::Affiche()const
{
	cout<<endl<<"Nom: "<<nom<<endl;
	cout<<"Puissance: "<<puissance<<"ch"<<endl;
	cout<<"Prix de base: "<<prixDeBase<<"€"<<endl;
	cout<<"Moteur: ";

	switch(moteur)
	{
		case Essence:
			cout<<"Essence"<<endl<<endl;
			break;
		case Diesel:
			cout<<"Diesel"<<endl<<endl;
			break;
		case Electrique:
			cout<<"Electrique"<<endl<<endl;
			break;
		case Hybride:
			cout<<"Hybride"<<endl<<endl;
			break;
	}
}*/