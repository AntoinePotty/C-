#include "Vecteur.h"
#include "VecteurTrie.h"
#include "Client.h"

#include <iostream>

using namespace std;

/**********************************************************************************************************/
/***************** Constructeur/Destructeur ***************************************************************/
/**********************************************************************************************************/

template <class T> 
VecteurTrie<T> :: VecteurTrie(): Vecteur<T>()
{
	#ifdef DEBUG
		cout << "Constructeur par defaut de VecteurTrie" << endl;
	#endif
}


template <class T> 
VecteurTrie<T> :: VecteurTrie(int max): Vecteur<T>(max)
{
	#ifdef DEBUG
		cout << "Constructeur d'initialisation VecteurTrie _sizeMax :" << max <<endl;
	#endif
}

template <class T> 
VecteurTrie<T> :: VecteurTrie(const VecteurTrie<T>& Vec): Vecteur<T>(Vec)
{
	#ifdef DEBUG
		cout << "Constructeur de copie VecteurTrie _sizeMax" << Vec.sizeMax() << "_size" << Vec.size() << endl;
	#endif
}

template <class T> 
VecteurTrie<T> ::~VecteurTrie()
{
	#ifdef DEBUG
		cout << "Destructeur du VecteurTrie" <<endl;
	#endif
}

/**********************************************************************************************************/
/***************** Surchargeur ****************************************************************************/
/**********************************************************************************************************/


template <class T>
void VecteurTrie<T>::insere(const T & val)
{
	#ifdef DEBUG
		cout << "VecteurTrie<T>::insere =" << endl;
	#endif

	int i,j;
	
	if(this->size() == this->sizeMax())
		cout << "Il n'y a pas de place dans le vecteur trie" << endl;
	else
	{
		for(i=0 ; i < this->size() && this->v[i] < val ; i++);

		
		for(j=(this->size()) + 1 ; j > i ; j--)
			this->v[j] = this->v[j-1];


		this->v[j] = val;/////////////////////////
	}
	this->_size++;
}