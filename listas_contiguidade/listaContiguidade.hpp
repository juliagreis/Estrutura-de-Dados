#ifndef LISTA
#define LISTA

#include <iostream>
#include <exception>

//Excessao usada pela classe MyVec
class MyVecException {
    private:
        std::string msg;
    public:
        MyVecException (const std::string &msg0): msg(msg0) { }
        const std::string & what() const { return msg; }
    };

template <class T>
class ListaContiguidade{


    private:

        //-------atributos------
        T* data;
        int dataSize;
        int dataCapacity;
        //-------funcoes-------

        void resizeCapacity(int newCapacity);
        
    

    public:

        ListaContiguidade();
        ListaContiguidade(int n, const T &init=T()); //Significa que se você não passar nenhum valor para init, ele será automaticamente inicializado com um valor padrão, gerado por T().
        ~ListaContiguidade();
        ListaContiguidade(const ListaContiguidade& aux);
        void pushback(const T& elem);
        void insert(const int pos, const T&elem);
        void clear();

        bool empty(); //verifica se a lista está vazia.
        int size();


        //----operadores----//
        ListaContiguidade& operator=(const ListaContiguidade& other);
        T& operator[](const int pos);
        const T& operator[](const int pos)const ;
};

//----operadores----//
template<class T>
ListaContiguidade<T>& ListaContiguidade<T>::operator=(const ListaContiguidade& other){
    if (this == &other) return *this; // proteção contra auto-atribuição - verifica se apontam para o mesmo endereco
    
    delete[] data; //deleta possivel memoria que o vetor poderia ter alocado;

    dataCapacity=other.dataCapacity;
    dataSize=other.dataSize;
    data=new T[dataCapacity];

    for(int i=0;i<dataSize;i++)
        data[i]=other.data[i];
    
    for(int i=dataSize;i<dataCapacity;i++)
        data[i]=T();   //inicializa os espacos nao ultilizados como padrao do tipo T
    
    return *this;
}

template<class T>
T& ListaContiguidade<T>::operator[](const int pos){
    if (pos < 0 || pos >= dataSize) {
        throw MyVecException("Índice fora dos limites.");
    }
    return data[pos];
}

template<class T>
const T& ListaContiguidade<T>::operator[](const int pos)const {
    if (pos < 0 || pos >= dataSize) {
        throw MyVecException("Índice fora dos limites.");
    }
    return data[pos];
}




//------construtores-------//
template <class T>
ListaContiguidade<T>::ListaContiguidade(){
    data=NULL;
    dataSize=dataCapacity=0;
}

template<class T>
ListaContiguidade<T>::ListaContiguidade(int n,const T& init){
    dataCapacity=n;
    dataSize=0;
    data=new T[n];
    //inicializando cada posicao da lista
    for(int i=0;i<n;i++){
        data[i]=init;
    }
}

//-------destrutor-------//
template<class T>
ListaContiguidade<T>::~ListaContiguidade(){
    delete[] data;
    dataCapacity=dataSize=0;
}

//-----funcoes auxiliares de manipulacao-----//

template<class T>
ListaContiguidade<T>::ListaContiguidade(const ListaContiguidade& original){
    data=NULL;
    dataSize=dataCapacity=0;
    *this=original;
}



template<class T>
void ListaContiguidade<T>::pushback(const T& elem){

    if(0==dataCapacity&&0==dataSize) resizeCapacity(dataCapacity+1);
    else if (dataCapacity==dataSize) resizeCapacity(dataCapacity*2);

    data[dataSize]=elem;
    dataSize++;
}

template<class T>
void ListaContiguidade<T>::resizeCapacity(int newCapacity){
    if(newCapacity<dataCapacity) return;

    T* aux=data;  //guardamos o endereco do vetor no auxiliar
    data=new T[newCapacity];
    for(int i=0;i<dataSize;i++){
        data[i]=aux[i];
    }
    delete[] aux;
    dataCapacity=newCapacity;

}

template<class T>
void ListaContiguidade<T>::insert(const int pos, const T&elem){
    if(pos>dataSize || pos<0)
        throw  MyVecException("Erro na funcao insert: posicao invalida");
    
    if(dataSize+1>dataCapacity){
        if(dataCapacity==0)
            resizeCapacity(1);
        
        else
            resizeCapacity(dataCapacity+1);
    }

    //agora que o vetor ja tem o tamanho necessario
    //coloamos todos os valores, a partir de pos, uma casa pra frente
    //mas realizamos de tras pra frente
    for(int i=dataSize;i>pos;i--){
        data[i]=data[i-1];
    }
    data[pos]=elem;
    
}
template<class T>
void ListaContiguidade<T>::clear(){
    delete[] data;
    dataSize=dataCapacity=0;
    data=NULL;
}

template<class T>
bool ListaContiguidade<T>::empty(){
    return dataSize==0;
}
template<class T>
int ListaContiguidade<T>::size(){
    return dataSize;
}


#endif