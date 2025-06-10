#include <iostream>
#include "Set_bpm.hpp" 

template <class T>
void imprime(Set_BPM<T> &arvore){
    Set_BPM_iterator<T> b = arvore.begin();
    Set_BPM_iterator<T> e = arvore.end();
    while(b != e){
        std::cout << *b << " ";
        ++b;
    }
    std::cout << std::endl;
}

int main() {
    Set_BPM<int> conjunto;

    // Inserções
    conjunto.insert(10);
    conjunto.insert(5);
    conjunto.insert(15);
    conjunto.insert(2);
    conjunto.insert(8);
    conjunto.insert(12);
    conjunto.insert(20);
    conjunto.insert(3);

    // Inserção duplicada
    std::pair<Set_BPM<int>::iterator, bool> resultado = conjunto.insert(10);
    if (!resultado.second) {
        std::cout << "Elemento 10 repetido, nao inserido\n";
    }

    // Busca existente
    Set_BPM<int>::iterator it = conjunto.find(8);
    if (it != conjunto.end()) {
        std::cout << "Encontrado: " << *it << std::endl;
    } else {
        std::cout << "8 nao encontrado\n";
    }

    // Busca inexistente
    Set_BPM<int>::iterator it2 = conjunto.find(99);
    if (it2 == conjunto.end()) {
        std::cout << "99 nao encontrado\n";
    }

    // Percursos
    std::cout << "\nDFS - Pre-ordem: ";
    conjunto.imprimeDFS_pre_order();
    std::cout << "\nDFS - Em-ordem: ";
    conjunto.imprimeDFS_in_order();
    std::cout << "\nDFS - Pos-ordem: ";
    conjunto.imprimeDFS_pos_order();

    std::cout << "\n\nBFS: \n";
    conjunto.imprimeBFS();

    // Iteração com imprime()
    std::cout << "\nIterando com imprime(): ";
    imprime(conjunto);

    // Teste de cópia
    Set_BPM<int> copia;
    copia = conjunto;

    std::cout << "Cópia da árvore com imprime(): ";
    imprime(copia);

    return 0;
}
