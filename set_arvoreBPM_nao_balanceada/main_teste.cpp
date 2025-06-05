#include <iostream>
#include "Set_bpm.hpp"  // ajuste o caminho conforme necessário

int main() {
    Set_BPM<int> conjunto;

    std::pair<Set_BPM<int>::iterator, bool> resultado1 = conjunto.insert(10);
    std::pair<Set_BPM<int>::iterator, bool> resultado2 = conjunto.insert(5);
    std::pair<Set_BPM<int>::iterator, bool> resultado3 = conjunto.insert(15);
    std::pair<Set_BPM<int>::iterator, bool> resultado4 = conjunto.insert(10); // valor repetido

    if (resultado1.second) std::cout << "10 inserido\n";
    else std::cout << "10 ja existia\n";

    if (resultado4.second) std::cout << "10 inserido novamente\n";
    else std::cout << "10 repetido, nao inserido\n";

    Set_BPM<int>::iterator it = conjunto.find(5);
    if (it != conjunto.end()) {
        std::cout << "Encontrado: " << *it << std::endl;
    } else {
        std::cout << "5 nao encontrado\n";
    }

    Set_BPM<int>::iterator it2 = conjunto.find(99);
    if (it2 == conjunto.end()) {
        std::cout << "99 nao encontrado\n";
    }

    return 0;
}
