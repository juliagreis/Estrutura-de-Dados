#include <algorithm>
#include "MyQueue.h"

//---------------------CLASSE NODE----------------------//
template  <class T>
class Node {
	public: //classe auxiliar.. vamos utiliza-la apenas neste arquivo (nao e' muito necessario ter encapsulamento)
		Node(const T &elem_) : elem(elem_),left(NULL), right(NULL), parent(NULL) {}
		Node<T> *left, *right, *parent;
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
        Set_BPM_iterator& operator++();  //nao recebe nada pois irá """somar""" 1 na memoria
	    Set_BPM_iterator& operator--();
        Set_BPM_iterator& operator++(int);  //esse int declarado é so pro compilador entender que é de pos incremento
        Set_BPM_iterator& operatorii(int);
};

template <class T>
Set_BPM_iterator<T>&Set_BPM_iterator<T>::operator++(int){
    Set_BPM_iterator<T> itaux(*this);
    ++(*this);
    return itaux;
}
template <class T>
Set_BPM_iterator<T>&Set_BPM_iterator<T>::operator++(int){
    Set_BPM_iterator<T> itaux(*this);
    --(*this);
    return itaux;
}
template<class T>
Set_BPM_iterator<T>& Set_BPM_iterator<T>::operator++(){
	//o menor elemento maior que ele, logo:
	if(ptr->right){
		ptr=ptr->right;
		//agora encontramos o menor (ou seja, mais a esquerda)
		while(ptr->left) ptr=ptr->left;
	}
	else{ // se nao tiver ninguem a direita dele, entao
		while(ptr->parent && ptr==ptr->parent->right){
			ptr=ptr->parent;
		}
		//suba + 1 vezes
		ptr=ptr->parent;
	}
	return *this;
}

template<class T>
Set_BPM_iterator<T>& Set_BPM_iterator<T>::operator--(){
	//o menor elemento maior que ele, logo:
	if(ptr->left){
		ptr=ptr->left;
		//agora encontramos o menor (ou seja, mais a esquerda)
		while(ptr->right) ptr=ptr->right;
	}
	else{ // se nao tiver ninguem a direita dele, entao
		while(ptr->parent && ptr==ptr->parent->left){
			ptr=ptr->parent;
		}
		//suba + 1 vezes
		ptr=ptr->parent;
	}
	return *this;
}




//-----------------------CLASSE SET-----------------------//


template <class T>
class Set_BPM{
    public:
        typedef Set_BPM_iterator<T> iterator;
        Set_BPM();
        Set_BPM(const Set_BPM &other);
        ~Set_BPM();

        iterator begin();
        iterator end(){return iterator(NULL);}


        std::pair<iterator,bool> insert(const T& elem);
        iterator find(const T& elem);

        Node<T>* copiaNodes(Node<T> * root,Node<T> *parent) const;
        Set_BPM &operator=(const Set_BPM &other);

        //bfs e dfs
        /*
            CONTEÚDO 2: PERCURSO
            Há diversas maneiras de percorrer uma árvore 

            1--BFS-> percorre nível a nível  (uso de pilha)

            2--DFS->visita-se o nodo e cada um dos filhos de forma recursiva(esquerda para direita ou o cnotrário)
            Pré-ordem (preorder): Visita o nó atual → esquerda → direita
            Em-ordem (inorder): Esquerda → nó atual → direita
            Pós-ordem (postorder): Esquerda → direita → nó atual

        */
       void imprimeBFS()const;

       void imprimeDFS_pre_order()const;
       void imprimeDFS_in_order()const;
       void imprimeDFS_pos_order()const;

        
    private:

        Node<T> * root;
        T elem;
        int size;
        //funcoes auxiliares
        std::pair<iterator,bool>insert_recursion(const T& elem, Node<T> * &root, Node<T> *parent);
        iterator find_recursion(const T& elem, Node<T> * &root);
        void delete_recursion(Node<T> *root);

        void preOrder(const Node<T> *root)const;
        void inOrder(const Node<T> *root)const;
        void posOrder(const Node<T> *root)const;

    
};

template <class T>
Set_BPM<T>::Set_BPM(){ root=NULL; size=0;}

template <class T>
Set_BPM<T>::Set_BPM(const Set_BPM &other){
    root = NULL;
    size = 0;
    root = copiaNodes(other.root, NULL);
    size = other.size;
}

template <class T>
void Set_BPM<T>::delete_recursion(Node<T> *root){
    //nao preciso tratar se os filhos sao null pq o proprio compilador ira ignorar o delete se este for o caso
    if(root==NULL) return;
    delete_recursion(root->left);
    delete_recursion(root->right);
    delete root;
}

template <class T>
Set_BPM<T>::~Set_BPM() {
    delete_recursion(root);
}

template <class T>
Set_BPM_iterator<T> Set_BPM<T>::begin(){
    if (root==NULL) return end();
    Node<T> *aux=root;
    while(aux->left) aux=aux->left;
    return iterator(aux);
}

template<class T>
std::pair<typename Set_BPM<T>::iterator,bool> Set_BPM<T>::insert_recursion(const T& elem, Node<T> * &root, Node<T> *parent){
    if(!root){
        size++;
        root=new Node<T>(elem);
        root->parent=parent;
        return std::make_pair(iterator(root), true);
    }

    if(elem < root->elem) return insert_recursion(elem,root->left,root);
    else if(elem>root->elem) return insert_recursion(elem,root->right,root);
    else return std::make_pair(iterator(root), false);
}

template<class T>
std::pair<typename Set_BPM<T>::iterator,bool> Set_BPM<T>::insert(const T& elem){
    return insert_recursion(elem, root,NULL);
}

template<class T>
typename Set_BPM<T>::iterator Set_BPM<T>:: find_recursion(const T& elem, Node<T> * &root){
    if(!root) return iterator(NULL);
    else if(root->elem < elem) return find_recursion(elem,root->right);
    else if(root->elem > elem) return find_recursion(elem,root->left);
    return iterator(root);
}

template <class T>
typename Set_BPM<T>::iterator Set_BPM<T>::find(const T& elem){
    return find_recursion(elem,root);
}

template <class T>
Node<T>* Set_BPM<T>::copiaNodes(Node<T> * root,Node<T> *parent)const {
    if(root==NULL) return NULL;

    Node<T> *aux=new Node<T>(root->elem); //fiz um node de mesmo valor
    aux->parent=parent;
    aux->left=copiaNodes(root->left,aux);
    aux->right=copiaNodes(root->right,aux);

    return aux;
}

template <class T>
Set_BPM<T>& Set_BPM<T>::operator=(const Set_BPM<T> &other){
    //verificamos se estamos tentando uma auto-atibuicao
    if(this==&other) return *this;
    //garantimos que other está vazio
    delete_recursion(root);
    root = NULL;
    size = 0;
    
    root=copiaNodes(other.root,NULL);
    size=other.size;
    return *this;

}

template<class T>
void Set_BPM<T>::imprimeBFS()const{
    if(root==NULL) return;
    //vamos imprimir nivel a nivel da arvore utilizando uma fila -> da esquerda para a direita
    MyQueue<Node<T>*> fila;
    fila.push(root);

    while(!fila.empty()){
        Node<T> *aux= fila.front();
        fila.pop();
        std::cout<<aux->elem<<std::endl;
        if(aux->left) fila.push(aux->left);
        if(aux->right) fila.push(aux->right);
    }
}

template<class T>
void Set_BPM<T>::preOrder(const Node<T> *root)const{
    if(root==NULL) return;
    std::cout<<root->elem<<" ";   //a impressao ocorre pre
    preOrder(root->left);
    preOrder(root->right);
}

template<class T>
void Set_BPM<T>::imprimeDFS_pre_order()const{
    //Pré-ordem (preorder): Visita o nó atual → esquerda → direita
    preOrder(root);
}

template<class T>
void Set_BPM<T>::inOrder(const Node<T> *root)const{
    if(root==NULL) return;
    inOrder(root->left);
    std::cout<<root->elem<<" ";   //a impressao ocorre in
    inOrder(root->right);
}

template<class T>
void Set_BPM<T>::imprimeDFS_in_order()const{
    //Pré-ordem (preorder): Visita o esquerda→ nó atual → direita
    inOrder(root);
}

template<class T>
void Set_BPM<T>::posOrder(const Node<T> *root)const{
    if(root==NULL) return;
    posOrder(root->left);
    posOrder(root->right);
    std::cout<<root->elem<<" ";   //a impressao ocorre pos
}

template<class T>
void Set_BPM<T>::imprimeDFS_pos_order()const{
    //Pré-ordem (preorder): Visita o esquerda→ nó atual → direita
    posOrder(root);
}