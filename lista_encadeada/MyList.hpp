#ifndef MYLIST
#define MYLIST

#include "Node.hpp"

template<class T>
class MyList{

    private:

        //-----------atributos----------//
        Node<T> *dataLast;
        Node<T> *dataFirst;
        int dataSize;
    public:
        //-----------funcoes----------//
        MyList();  //ok
        ~MyList();  //ok
        void destroy();                 //verificar
        void pushback(const T& elem);   //ok
        void pushfront(const T& elem);  //ok
        void insert(const T& elem,const int pos);   //ok
        void print()const ;   //ok

        int size(){return dataSize;}
        bool empty(){return dataSize==0}
};

//____construtor e destrutor____//

template<class T>
MyList<T>::MyList(){
    dataSize=0;
    dataFirst=dataLast=NULL;
}

template<class T>
void MyList<T>::destroy(){
    Node<T>* current = dataFirst;
    while (current != NULL) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    dataFirst = dataLast = NULL;
    dataSize = 0;
}


template<class T>
MyList<T>::~MyList(){
    destroy();
}

//-------push-back / front-----//
template<class T>
void MyList<T>::pushback(const T& elem){
    Node<T>* novo=new Node<T>(elem);
    //se a lista estiver vazia
    if(dataFirst==NULL){
        dataFirst=dataLast=novo;
    }
    else{
        dataLast->next=novo;
        dataLast=novo;
    }
    dataSize++;
}

template<class T>
void MyList<T>::pushfront(const T& elem){
    if(dataSize==0){
        pushfront(elem);
        return;
    }
    Node<T>* aux= new Node<T>(elem);
    aux->next=dataFirst;
    dataFirst=aux;
    dataSize++;
}

//--------insert-------//

template<class T>
void MyList<T>::insert(const T& elem, const int pos){

    if(pos==0){ //se quiser adicionar no comeco
        pushfront(elem);
        return;
    }
    else if(pos==dataSize){
        pushback(elem);
        return;
    }
    else if(pos>dataSize){
        std::cout<<"erro!"<<std::endl;    //falta tratamento de excessao
    }
    else{

    //para casos que a posicao possui um elemento anterior e um posterior a ele
    Node<T> *anterior;
    for(int i=0;i<pos-1;i++){ //busca o node que aponta para a posicao
        anterior=dataFirst->next;
    }
    Node<T> *novo=new Node<T>(elem);
    novo->next=anterior->next;
    anterior->next=novo;
    dataSize++;
    }
}

//-----print------//
template<class T>
void MyList<T>::print() const{

    Node<T> * aux=dataFirst;
    for(int i=0;i<dataSize;i++){
        std::cout<<aux->data<<std::endl;
        aux=aux->next;
   }
}



#endif