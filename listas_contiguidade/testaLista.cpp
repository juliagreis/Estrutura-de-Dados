#include "listaContiguidade.hpp" 

int main() {
    // Criando uma lista de inteiros
    ListaContiguidade<int> lista;

    // Testando o método pushback
    lista.pushback(10);
    lista.pushback(20);
    lista.pushback(30);
    lista.pushback(40);

    std::cout << "Lista após inserções:" << std::endl;
    for (int i = 0; i < lista.size(); i++) {
        std::cout << lista[i] << " ";  // Usando o operador[] para acessar elementos
    }
    std::cout << std::endl;

    // Testando o operador de atribuição
    ListaContiguidade<int> listaCopy;
    listaCopy = lista;  // Atribuindo a lista original para a listaCopy

    std::cout << "Lista copiada após atribuição:" << std::endl;
    for (int i = 0; i < listaCopy.size(); i++) {
        std::cout << listaCopy[i] << " ";  // Usando o operador[] para acessar elementos
    }
    std::cout << std::endl;

    // Testando o método insert
    lista.insert(2, 25);  // Inserindo 25 na posição 2 (entre 20 e 30)

    std::cout << "Lista após inserção do 25 na posição 2:" << std::endl;
    for (int i = 0; i < lista.size(); i++) {
        std::cout << lista[i] << " ";  // Usando o operador[] para acessar elementos
    }
    std::cout << std::endl;

    // Testando o método clear
    lista.clear();
    std::cout << "Lista após o método clear (tamanho = " << lista.size() << "):" << std::endl;
    std::cout << (lista.empty() ? "Lista está vazia" : "Lista não está vazia") << std::endl;

    return 0;
}
