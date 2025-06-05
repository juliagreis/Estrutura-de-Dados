#include <algorithm>

//---------------------CLASSE NODE----------------------//
template  <class T>
class Node {
	public: //classe auxiliar.. vamos utiliza-la apenas neste arquivo (nao e' muito necessario ter encapsulamento)
		Node(const T &elem_) : elem(elem_),left(NULL), right(NULL) {}
		Node<T> *left, *right;
		T elem;
};

//--------------------CLASSE ITERADOR-------------------//
template <class T>
class Set_BPM;

template<class T>
class Set_BPM_iterator{
        friend class Set_BPM<T>;
    private:
        Node<T> *ptr;
    public:
        Set_BPM_iterator(Node<T> *ptr_){ptr=ptr_;};

        //operators
        T& operator*(){return ptr->elem;};
        bool operator==(const Set_BPM_iterator &other){return ptr==other.ptr;}
        bool operator!=(const Set_BPM_iterator &other){return !(ptr==other.ptr);}
};




//-----------------------CLASSE SET-----------------------//


template <class T>
class Set_BPM{
    public:
        typedef Set_BPM_iterator<T> iterator;
        Set_BPM();
        ~Set_BPM();

        iterator begin(){return iterator(root);}
        iterator end(){return iterator(NULL);}


        std::pair<iterator,bool> insert(const T& elem);
        iterator find(const T& elem);
        
    private:

        Node<T> * root;
        T elem;
        int size;
        //funcoes auxiliares
        std::pair<iterator,bool>insert_recursion(const T& elem, Node<T> * &root);
        iterator find_recursion(const T& elem, Node<T> * &root);

    
};

template <class T>
Set_BPM<T>::Set_BPM(){ root=NULL; size=0;}
template <class T>
Set_BPM<T>::~Set_BPM() {}

template<class T>
std::pair<typename Set_BPM<T>::iterator,bool> Set_BPM<T>::insert_recursion(const T& elem, Node<T> * &root){
    if(!root){
        size++;
        root=new Node<T>(elem);
        return std::make_pair(iterator(root), true);
    }

    if(elem < root->elem) return insert_recursion(elem,root->left);
    else if(elem>root->elem) return insert_recursion(elem,root->right);
    else return std::make_pair(iterator(root), false);
}

template<class T>
std::pair<typename Set_BPM<T>::iterator,bool> Set_BPM<T>::insert(const T& elem){
    return insert_recursion(elem, root);
}

template<class T>
typename Set_BPM<T>::iterator Set_BPM<T>:: find_recursion(const T& elem, Node<T> * &root){
    if(!root) return iterator(NULL);
    else if(root->left && root->elem < elem) return find_recursion(elem,root->right);
    else if(root->right && root->elem > elem) return find_recursion(elem,root->left);
    return iterator(root);
}

template <class T>
typename Set_BPM<T>::iterator Set_BPM<T>::find(const T& elem){
    return find_recursion(elem,root);
}