#ifndef LISTA_2
#define LISTA_2

#include "Node.hpp"

template<class T>
class Lista_2{
    private:
        Node<T>* dataFirst;
        Node<T>* dataLast;
        int dataSize;
    
    public:
        Lista_2();
        ~Lista_2();
        void destroy();  //funcao auxiliar do destrutor


        void pushBack(const T& elem);
        void pushFront(const T& elem);
        void insert(const T& elem,const int pos);
        void print();
        void clear();
        bool empty(){return dataSize==0;};

};

//----------construtor e destrutor------------//
template<class T>
Lista_2<T>::Lista_2(){
    dataFirst=dataLast=NULL;
    dataSize=0;
}
template<class T>
Lista_2<T>::~Lista_2(){
    if(empty()) return;
    Node<T>* aux=dataFirst;
    while(aux!=NULL){
        Node<T>* temp=aux;
        aux=aux->next;
        delete temp;
    } 
}

//-----------push back, pushfront-------------//
template<class T>
void Lista_2<T>::pushBack(const T& elem){
    if(empty()){
        dataFirst=dataLast=new Node<T>(elem);
        dataSize++;
        return;
    }
    Node<T>* aux=new Node<T>(elem);
    dataLast->next=aux;
    aux->prev=dataLast;
    dataLast=aux;
    dataSize++;
}

template<class T>
void Lista_2<T>::pushFront(const T& elem){
    if(empty()) {
        pushBack(elem);
        return;
    }
    Node<T>* aux=new Node<T>(elem);
    aux->next=dataFirst;
    dataFirst->prev=aux;
    dataFirst=aux;
    dataSize++;
}

//---------insert-------//

template<class T>
void Lista_2<T>::insert(const T& elem, const int pos){
    if(pos==dataSize){
        pushBack(elem);
    }
    else if(pos==0){
        pushFront(elem);
    }
    else{
        Node<T>* anterior=dataFirst;
        for(int i=0;i<pos-1;i++){
            anterior=anterior->next;
        }
        Node<T>* posterior=anterior->next;

        Node<T>* aux=new Node<T>(elem);
        aux->next=posterior;
        posterior->prev=aux;
        aux->prev=anterior;
        anterior->next=aux;

        dataSize++;
    }
}   


//---------print--------//
template<class T>
void Lista_2<T>::print(){
    Node<T>* aux=dataFirst;
    while(aux!=NULL){
        std::cout<<aux->data<<" ";
        aux=aux->next;
    }
}

#endif