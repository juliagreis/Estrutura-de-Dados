# 📚 ListaContiguidade

Este projeto implementa uma **lista com alocação contígua** (semelhante a um `std::vector`), usando templates em C++ para suportar qualquer tipo de dado.

---

## 📌 Descrição

A `ListaContiguidade<T>` é uma estrutura de dados baseada em vetores dinâmicos. A lista armazena os elementos em uma área contígua de memória e gerencia automaticamente o redimensionamento conforme novos elementos são inseridos.

### Características:

- ✅ **Genérica**: Usa templates para funcionar com qualquer tipo `T`.
- 🔁 **Dinâmica**: Capacidade cresce automaticamente quando necessário.
- 🛡️ **Segura**: Verificação de limites ao acessar elementos.
- ⚠️ **Exceções personalizadas**: Para mensagens de erro descritivas.

---

## 🧰 Tecnologias Utilizadas

- **C++**: Linguagem principal utilizada no projeto.
- **Templates**: Permite que a estrutura funcione com qualquer tipo de dado (`ListaContiguidade<T>`).
- **Programação orientada a objetos**: Com uso de classes, encapsulamento e construtores/destrutores.
- **Gerenciamento manual de memória**: Alocação e desalocação de arrays com `new` e `delete[]`.
- **Tratamento de exceções**: Com a classe `MyVecException` para capturar erros de uso.

---

## 🔧 Funcionalidades implementadas

| Método / Operador             | Descrição                                                                 |
|-------------------------------|---------------------------------------------------------------------------|
| `pushback(const T&)`          | Adiciona um novo elemento ao final da lista.                             |
| `insert(int pos, const T&)`   | Insere um elemento na posição indicada, deslocando os demais.            |
| `clear()`                     | Remove todos os elementos da lista.                                      |
| `empty()`                     | Verifica se a lista está vazia.                                          |
| `size()`                      | Retorna o número de elementos na lista.                                  |
| `operator[](int)`             | Acessa um elemento com verificação de limites.                           |
| `operator=`                   | Realiza cópia profunda de uma lista para outra.                          |
| Construtores e destrutor      | Inicialização, cópia e liberação automática de memória.                  |

---

## ⚙️ Gerenciamento de capacidade

- O vetor é redimensionado automaticamente pela função `resizeCapacity(int)`.
- Ao fazer `pushback`, se a lista estiver cheia, a capacidade é dobrada.
- Durante `insert`, a capacidade é aumentada em +1 se necessário.

---

## 🚨 Tratamento de erros

A classe `MyVecException` é usada para lançar erros como:

- Índices fora dos limites.
- Inserção em posições inválidas.

Exemplo:
```cpp
if (pos < 0 || pos >= dataSize) {
    throw MyVecException("Índice fora dos limites.");
}

