#ifndef NODE_HPP
#define NODE_HPP

#include <stdlib.h>
#include <iostream>

template<class T>
class Node{
    friend class MyList;
    public:
        Node<T>* prev;  //ponteiro para o nodo anterior
        Node<T>* next;  //ponteiro para o proximo nodo
        T data;

        Node();
        ~Node();
        Node(const T& elem);
};



//-----construtores e destrutor-----//
template<class T>
Node<T>::Node(){
    prev=NULL;
    next=NULL;
    data=NULL;
}
template<class T>
Node<T>::Node(const T& elem){
    data=elem;
    prev=NULL;
    next=NULL;
}
template<class T>
Node<T>::~Node(){
    data=T();
}
#endif