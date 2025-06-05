#include "lista_dupla.hpp"  // Certifique-se de incluir o cabeçalho da classe Lista_2

int main() {
    // Criação da lista
    Lista_2<int> lista;

    // Testando pushFront (inserir no início)
    std::cout << "Inserindo 10 no início (pushFront):" << std::endl;
    lista.pushFront(10);
    lista.print();  // Esperado: 10

    // Testando pushBack (inserir no final)
    std::cout << "Inserindo 20 no final (pushBack):" << std::endl;
    lista.pushBack(20);
    lista.print();  // Esperado: 10 20

    // Testando insert (inserir no meio)
    std::cout << "Inserindo 15 na posição 1 (insert):" << std::endl;
    lista.insert(15, 1);
    lista.print();  // Esperado: 10 15 20

    // Testando inserção na primeira posição
    std::cout << "Inserindo 5 na posição 0 (insert):" << std::endl;
    lista.insert(5, 0);
    lista.print();  // Esperado: 5 10 15 20

    // Testando inserção no final (com pos == dataSize)
    std::cout << "Inserindo 25 na posição 4 (insert no final):" << std::endl;
    lista.insert(25, 4);
    lista.print();  // Esperado: 5 10 15 20 25

    return 0;
}
