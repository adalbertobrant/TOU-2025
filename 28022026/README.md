# Algoritmos de Ordenação e Revisão de C++

Este repositório contém o material de estudo e códigos de exemplo sobre algoritmos de ordenação, com foco em **Merge Sort** e a função `std::sort` do C++, além de uma revisão fundamental de **Structs** e **Ponteiros**.

## 📚 Materiais e Slides

Abaixo estão os links para os materiais teóricos utilizados:

*   **Parte 1 - Ordenação:** [PDF](8%20-%20ORDENAÇÃO%20-%20PARTE%201.pdf)
*   **Parte 2 - Ordenação:** [PDF](9%20-%20ORDENAÇÃO%20-%20PARTE%202.pdf)

### Código Fonte de Exemplo
*   [`revisao_struct_pointer.cpp`](revisao_struct_pointer.cpp): Revisão básica de estruturas.
*   [`merge.cpp`](merge.cpp): Implementação passo a passo do Merge Sort com medição de tempo.
*   [`diff_sort_merge.cpp`](diff_sort_merge.cpp): Comparação de desempenho entre Merge Sort manual e o `std::sort`.

---

## ⚡ Ordenação em C++

### Merge Sort
O **Merge Sort** é um algoritmo do tipo "Dividir para Conquistar". Ele funciona dividindo o vetor recursivamente em duas metades até que cada sub-vetor tenha apenas um elemento. Em seguida, ele "mescla" (merge) esses sub-vetores de forma ordenada.
*   **Complexidade:** O(n log n) no pior caso.-> é muito bom mas não é O(0) , nem O(1) , O(log n), O (n).
*   **Vantagem:** Estável e muito eficiente para grandes volumes de dados.

### A Função `std::sort`
No C++, a biblioteca `<algorithm>` fornece a função `sort()`, que é extremamente otimizada (geralmente implementando o *Introsort*).
*   **Como usar:**
    ```cpp
    int v[] = {5, 2, 9, 1, 5};
    int n = 5;
    sort(v, v + n); // Ordena de v[0] até v[n-1]
    ```

---

## 🔍 Ponteiros e Structs

### Structs
As `structs` permitem criar novos tipos de dados que agrupam diferentes variáveis sob um mesmo nome. É o primeiro passo para a Orientação a Objetos.

```cpp
struct Aluno {
    string nome;
    int matricula;
};
```

### Ponteiros
Um ponteiro é uma variável que armazena o **endereço de memória** de outra variável.
*   `&variavel`: Acessa o endereço.
*   `*ponteiro`: Acessa o valor armazenado no endereço (desreferenciação).

### Formas de Acesso
Ao lidar com structs e ponteiros, usamos dois operadores principais:
1.  **Operador ponto (`.`):** Usado quando temos o objeto diretamente.
    ```cpp
    Aluno a;
    a.nome = "Joao";
    ```
2.  **Operador seta (`->`):** Usado quando temos um **ponteiro** para o objeto.
    ```cpp
    Aluno *ptr = &a;
    ptr->nome = "Joao"; // Equivalente a (*ptr).nome
    ```

---

## 🌳 Por que aprender isso agora?

Entender ponteiros e structs é **obrigatório** para o estudo de estruturas de dados avançadas que veremos a seguir:
*   **Listas Encadeadas:** Cada elemento aponta para o próximo via ponteiros.
*   **Árvores (Trees):** Cada "nó" da árvore é uma `struct` que contém ponteiros para seus filhos (esquerda e direita).
*   **Grafos:** Utilizam listas de adjacência que dependem fortemente de alocação dinâmica e ponteiros.

Sem o domínio de ponteiros, é impossível conectar os nós de uma árvore ou gerenciar a memória de forma eficiente.

---

## 📝 Exercícios de Fixação (Plataforma NEPS)

Para praticar, resolva os seguintes problemas na [NEPS Academy](https://neps.academy/br):

### Ordenação
1.  [Matryoshka](https://neps.academy/br/course/programacao-basica-(codcad)/lesson/matryoshka)
2.  [Olimpíadas](https://neps.academy/br/exercise/221)
3.  [Merge Sort (Implementação)](https://neps.academy/br/exercise/229)

### Ponteiros, Structs e Funções
1.  [Função Primo](https://neps.academy/br/exercise/247) (Prática de Funções)
2.  [Gincana](https://neps.academy/br/exercise/253) (Pode ser resolvido com structs)
3.  [Passagem de Parâmetros](https://neps.academy/br/course/programacao-em-c++-(intermediario)/lesson/passagem-por-valor-e-por-referencia) (Entender referência vs ponteiros)

