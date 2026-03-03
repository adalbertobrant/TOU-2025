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
3.  [MergeSort](Implementação)](https://www.ime.usp.br/~pf/algorithms/chapters/mergesort.html)

### Ponteiros, Structs e Funções
1.  [Função Primo](https://neps.academy/br/exercise/247) (Prática de Funções)
2.  [Times](https://neps.academy/br/exercise/253) (Pode ser resolvido com structs)
3.  [Passagem de Parâmetros](https://github-pages.ucl.ac.uk/research-computing-with-cpp/02cpp1/sec02PassByValueOrReference.html) (Entender referência vs ponteiros)

## 📝 Exercícios de Desafio 

## O Problema do Tempo Líquido

## Contexto

Em grandes corridas de rua, o volume de participantes impede que todos cruzem a linha de partida ao mesmo tempo. Para resolver isso, a organização utiliza chips eletrônicos. O **Tempo Bruto** é cronometrado a partir do sinal de largada (o "tiro"), enquanto o **Tempo Líquido** é o tempo real que o corredor levou para completar o percurso, contado apenas a partir do momento em que ele cruza o tapete de largada até o momento em que cruza o tapete de chegada.

Sua tarefa é desenvolver um sistema que receba os dados dos chips e gere a classificação oficial baseada no Tempo Líquido.

---

## Problema

Dada uma lista de $N$ corredores, cada um com um identificador único (ID) e dois registros de tempo (instante de largada e instante de chegada), calcule o tempo líquido de cada um e ordene-os do menor para o maior tempo.

### Regra de Desempate

Caso dois corredores possuam o exato mesmo tempo líquido, o critério de desempate deve ser a **ordem de chegada** (quem cruzou a linha de chegada primeiro no tempo bruto).

---

## Entrada

A primeira linha contém um inteiro $N$ ($1 \le N \le 10.000$), representando o número de corredores.

As $N$ linhas seguintes contêm, cada uma, três valores:

- Um inteiro **ID** ($1 \le ID \le 100.000$)
- Um valor real **T_Inicio** (o instante em que o chip ativou na largada)
- Um valor real **T_Fim** (o instante em que o chip ativou na chegada)

---

## Saída

A saída deve conter $N$ linhas, cada uma com:

- A posição do corredor
- Seu ID
- Seu tempo líquido com duas casas decimais

Os corredores devem estar ordenados do 1º ao último colocado.

---

## 🟢 Caso 1: O Básico (Funcionamento Geral)

**Objetivo:** Verificar se o cálculo $T_{fim} - T_{inicio}$ está correto e se a ordenação básica funciona.

**Entrada:**

```text
3
10 5.0 15.0
20 0.0 12.0
30 2.0 11.0

```

* *Corredor 10:* $15 - 5 = 10s$
* *Corredor 20:* $12 - 0 = 12s$
* *Corredor 30:* $11 - 2 = 9s$

**Saída Esperada:**

```text
1. ID: 30 | Tempo: 9.00s
2. ID: 10 | Tempo: 10.00s
3. ID: 20 | Tempo: 12.00s

```

---

## 🟡 Caso 2: A "Largada Tardia" (O Corredor que sai por último mas ganha)

**Objetivo:** Validar se o sistema ignora o tempo bruto e foca no tempo de chip (líquido).

**Entrada:**

```text
2
500 0.0 100.0
600 50.0 140.0

```

* *Explicação:* O ID 500 chegou primeiro no relógio oficial (100s), mas o ID 600 correu o trajeto em 90s (140 - 50), sendo o verdadeiro vencedor.

**Saída Esperada:**

```text
1. ID: 600 | Tempo: 90.00s
2. ID: 500 | Tempo: 100.00s

```

---

## 🔴 Caso 3: Empate Técnico (Critério de Desempate)

**Objetivo:** Testar se o código mantém a ordem de quem cruzou a linha de chegada primeiro em caso de tempos líquidos iguais.

**Entrada:**

```text
3
1 10.0 30.0
2 20.0 40.0
3 0.0 20.0

```

* *Análise:* Todos fizeram 20.00s de tempo líquido. A ordem deve ser baseada no `T_Fim`: Corredor 3 (chegou aos 20s), seguido pelo Corredor 1 (chegou aos 30s) e Corredor 2 (chegou aos 40s).

**Saída Esperada:**

```text
1. ID: 3 | Tempo: 20.00s
2. ID: 1 | Tempo: 20.00s
3. ID: 2 | Tempo: 20.00s

```

---

## 🟣 Caso 4: Stress Test (Performance)

**Objetivo:** Validar a eficiência $O(N \log N)$.

* **Entrada:** 10.000 linhas com IDs aleatórios e tempos com muitas casas decimais (ex: `ID 9999 123.456 789.012`).
* **Expectativa:** O programa deve processar e ordenar tudo em menos de **0.5 segundos**. Se usar um algoritmo $O(N^2)$ (como Bubble Sort), o programa travará ou excederá o tempo limite da olimpíada.

---

## Dica de Implementação (Snippet para o Comparador)

Para passar no **Caso 3**, o competidor precisará de um comparador assim:

```cpp
bool compare(const Corredor& a, const Corredor& b) {
    if (a.tempo_liquido != b.tempo_liquido) {
        return a.tempo_liquido < b.tempo_liquido;
    }
    return a.tempo_fim < b.tempo_fim; // Desempate por quem chegou primeiro no bruto
}

```

**Posso te ajudar a criar um script em Python para gerar automaticamente esses 10 mil nomes e tempos para você testar o código dos seus alunos?**
