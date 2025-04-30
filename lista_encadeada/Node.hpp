#ifndef LISTA_ENCADEADA
#define LISTA_ENCADEADA

#include <stdlib.h>
#include <iostream>
template<class T>
class Node{
    
    private:
        //-----------atributos----------//
        T data;
        Node<T> *next;
        //-----------funcoes----------//

    public:
        template<class U> friend class MyList;
        //-----------construtor e destrutor----------//
        Node();
        Node(const T& elem);
        ~Node();

};

//____construtores e destrutor____//
template<class T>
Node<T>::Node(){
    data=NULL;
    next=NULL;
}

template<class T>
Node<T>::Node(const T& elem){
    data=elem;
    next=NULL;
}

template<class T>
Node<T>::~Node(){
   next=NULL;
}


#endif