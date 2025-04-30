#ifndef ITERATOR
#define ITERATOR

#include "Node.hpp"
template<class T>
class Iterator{
    friend class MyList<T>;

    private:
        Node<T> *ptr;
    public:
        //construtor
        Iterator(Node<T> *p);
        T &operator*();
        const T &operator*()const ;
        bool operator==(const Iterator<T> &other) const ;
        bool operator!=(const Iterator<T> &other) const ;

};
template<class T>
Iterator<T>::Iterator(Node<T> *p){
    ptr=p;
}

template<class T>
T& Iterator<T>::operator*(){
    return *ptr;
}
template<class T>
const T& Iterator<T>::operator*()const{
    return *ptr;
}

template<class T>
bool Iterator<T>::operator==(const Iterator<T> &other) const{
    return ptr==other.ptr;
}

template<class T>
bool Iterator<T>::operator!=(const Iterator<T> &other) const{
    return !(ptr==other.ptr);
}



#endif