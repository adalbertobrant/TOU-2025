# TOU 2025 - 

# 🚀 Ordenação Avançada: Big O, Ponteiros, Alocação Dinâmica e Structs

## 📈 Notação Big O (Análise de Complexidade)

Antes de escolhermos um algoritmo de ordenação, precisamos entender como avaliar sua eficiência. A notação Big O, ou $O()$, descreve o limite superior do tempo de execução de um algoritmo ou do espaço de memória que ele consome à medida que o tamanho da entrada ($N$) cresce.

Em termos matemáticos formais, dizemos que uma função $f(n)$ é $O(g(n))$ se existem constantes positivas $c$ e $n_0$ tais que:


$$0 \le f(n) \le c \cdot g(n) \text{ para todo } n \ge n_0$$

Na prática, ignoramos as constantes e focamos no termo de maior crescimento.

### Exemplos de Aplicação no Dia a Dia

* **$O(1)$ - Constante:** Acessar o 5º elemento de um array (`vetor[4]`). O tempo é o mesmo, seja o array de tamanho 10 ou 10 milhões.
* **$O(N)$ - Linear:** Procurar um elemento não ordenado em um array passando de um por um (Busca Linear). Se dobrar o tamanho do array, dobra o tempo máximo de busca.
* **$O(N^2)$ - Quadrático:** Usar dois loops aninhados (`for` dentro de `for`) varrendo os mesmos dados. Comum em algoritmos de ordenação simples.
* **$O(N \log N)$ - Log-Linear:** Algoritmos eficientes de ordenação, que quebram o problema na metade sucessivamente (Merge Sort).

---

## 🏎️ Algoritmos de Ordenação e seus Tempos

Para entender a evolução da ordenação, vamos ver três abordagens com complexidades diferentes.

### 1. Tempo $O(N^2)$: Bubble Sort (Ordenação Bolha)

É um dos algoritmos mais simples, mas menos eficientes para grandes volumes de dados. Ele "flutua" o maior elemento para o final do array através de trocas adjacentes.

```c
// Complexidade: O(N^2) no pior caso e caso médio.
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int trocou = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocou = 1;
            }
        }
        // Se nenhuma troca ocorreu, o array já está ordenado
        if (!trocou) break; 
    }
}

```

### 2. Tempo $O(N \log N)$: Merge Sort (Ordenação por Mistura)

Usa a estratégia de "dividir para conquistar". Divide o array na metade até ficar com elementos isolados, e depois os junta (merge) já na ordem correta. Excelente para grandes volumes de dados.

```c
// Complexidade: O(N log N) em todos os casos. Requer O(N) de memória extra.
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2]; // Arrays temporários

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

```

### 3. Tempo $O(N)$: Counting Sort (Ordenação por Contagem)

Como é possível ordenar mais rápido que $O(N \log N)$? Quebrando a regra de "comparar elementos". O Counting Sort não compara números, ele os conta. Só funciona bem se o alcance dos números (valor máximo) for relativamente pequeno.

```c
// Complexidade: O(N + K), onde K é o valor máximo. Excelente se K for pequeno.
void counting_sort(int arr[], int n, int k) {
    int count[k + 1]; // Array de contagem
    int output[n];    // Array de saída
    
    // Inicializa contagem com zero
    for (int i = 0; i <= k; i++) count[i] = 0;
    
    // Conta a frequência de cada elemento
    for (int i = 0; i < n; i++) count[arr[i]]++;
    
    // Calcula a posição real de cada elemento
    for (int i = 1; i <= k; i++) count[i] += count[i - 1];
    
    // Constrói o array ordenado (percorrendo de trás para frente mantém a estabilidade)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    // Copia de volta
    for (int i = 0; i < n; i++) arr[i] = output[i];
}

```

---

## 🧠 Alocação Dinâmica de Memória (Heap)

Para manipular estruturas complexas e grandes, precisamos fugir da memória Stack (limitada e estática) e usar a Heap (dinâmica). Entender `malloc`, `calloc` e `realloc` é fundamental.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    // malloc: aloca memória não inicializada (traz "lixo" de memória)
    int* vetor1 = (int*)malloc(5 * sizeof(int));
    
    // calloc: aloca e inicializa tudo com ZERO (ótimo para evitar bugs)
    int* vetor_limpo = (int*)calloc(5, sizeof(int));
    
    // realloc: redimensiona memória previamente alocada, mantendo os dados antigos
    vetor_limpo = (int*)realloc(vetor_limpo, 10 * sizeof(int)); 
    
    // REGRA DE OURO: Sempre libere o que alocou!
    free(vetor1);
    free(vetor_limpo);
    
    return 0;
}

```

> 💡 **Dica em Competições**: Sempre verifique se o retorno não é `NULL` em softwares reais. Em competições como a maratona, isso geralmente não é o gargalo, mas esquecer o `free()` em loops infinitos causará o erro *Memory Limit Exceeded*.

## 🔗 Ponteiros e Passagem por Referência

Em C, tudo é passado por valor. Para alterar a variável original, passamos seu endereço de memória (ponteiro).

```c
#include <stdio.h>

// Função que troca dois valores usando ponteiros
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 3, y = 7;
    trocar(&x, &y); // Passamos o endereço de x e y
    // Agora x = 7, y = 3
    return 0;
}

```

---

## 📊 Ordenação de Structs com `qsort` (C) e `std::sort` (C++)

Seja usando C puro com `qsort` (`<stdlib.h>`) ou C++ com `std::sort` (`<algorithm>`), o segredo para ordenar dados complexos é a **Função de Comparação**.

### Abordagem C (`qsort`)

Exige o uso de ponteiros `void*` e casting.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

// Função de comparação multi-campo: Maior idade primeiro. Se empatar, nome em ordem alfabética.
int comparar_pessoas(const void* a, const void* b) {
    const Pessoa* p1 = (const Pessoa*)a;
    const Pessoa* p2 = (const Pessoa*)b;
    
    if (p1->idade != p2->idade) {
        return p2->idade - p1->idade; // Decrescente por idade
    }
    return strcmp(p1->nome, p2->nome); // Crescente por nome
}

int main() {
    Pessoa pessoas[] = {{"João", 25}, {"Maria", 30}, {"Ana", 25}};
    int n = 3;
    
    qsort(pessoas, n, sizeof(Pessoa), comparar_pessoas);
    // Resultado: Maria(30), Ana(25), João(25)
    
    return 0;
}

```

### Abordagem C++ (`std::sort`)

Muito mais limpa e otimizada (geralmente usa IntroSort, no pior caso é $O(N \log N)$).

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pessoa {
    string nome;
    int idade;
};

// Retorna VERDADEIRO se 'a' deve vir ANTES de 'b'
bool comparaPessoas(Pessoa a, Pessoa b) {
    if (a.idade != b.idade) {
        return a.idade > b.idade; // Maior idade primeiro
    }
    return a.nome < b.nome; // Ordem alfabética
}

int main() {
    vector<Pessoa> pessoas = {{"João", 25}, {"Maria", 30}, {"Ana", 25}};
    
    sort(pessoas.begin(), pessoas.end(), comparaPessoas);
    
    return 0;
}

```

---

## ⚙️ Meta-programação com `qsort`: Adaptando o Comparador

Em C, podemos usar ponteiros de função e contextos paramétricos para criar funções de ordenação extremamente genéricas.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int valor1;
    int valor2;
} Item;

// Estrutura para passar parâmetros ao comparador
typedef struct {
    int campo;  // 1=valor1, 2=valor2
    int ordem;  // 1=crescente, -1=decrescente
} ComparatorContext;

// Comparador dinâmico genérico
int comparar_generico(const void* a, const void* b, void* ctx) {
    const Item* item1 = (const Item*)a;
    const Item* item2 = (const Item*)b;
    ComparatorContext* context = (ComparatorContext*)ctx;
    
    int resultado = 0;
    if (context->campo == 1) resultado = item1->valor1 - item2->valor1;
    else if (context->campo == 2) resultado = item1->valor2 - item2->valor2;
    
    return resultado * context->ordem;
}

// Em um sistema real, essa variável estática atuaria como uma "closure" ou "functor" simplificado
static ComparatorContext contexto_atual;

int comparar_wrapper(const void* a, const void* b) {
    return comparar_generico(a, b, &contexto_atual);
}

int main() {
    Item itens[] = {{"Maçã", 5, 10}, {"Banana", 3, 7}};
    
    // Configura a meta-programação para ordenar pelo valor 2, DECRESCENTE
    contexto_atual.campo = 2;
    contexto_atual.ordem = -1;
    
    qsort(itens, 2, sizeof(Item), comparar_wrapper);
    
    return 0;
}

```

---

## 💪 Exercícios de Fixação

1. **O Filtro Dinâmico:** Crie um programa que leia um número $N$. Aloque um vetor dinâmico de tamanho $N$ usando `calloc`. Leia os números. Crie um novo vetor dinâmico apenas com os números pares lidos, usando `realloc` a cada número par encontrado. Libere a memória de ambos ao final.
2. **Torneio de Games (Struct + Sort):** Crie uma struct `Jogador` com `nickname`, `pontuacao` e `penalidades`. Use `std::sort` (ou `qsort`) para ordenar o ranking: Maior pontuação primeiro. Em caso de empate, o com menor penalidade. Empatou de novo? Ordem alfabética do nickname.
3. **Simulador de Fila de Banco:** Implemente um sistema onde clientes entram na fila (alocação dinâmica de um array de structs `Cliente`). Cada cliente tem `idade` e `tipo_atendimento`. Crie um `sort` que sempre jogue idosos (> 60 anos) para a frente, mantendo a ordem de chegada entre os idosos e entre os mais novos.
4. **Análise de Complexidade:** Escreva um pequeno texto calculando a complexidade de tempo de encontrar o maior valor não-repetido em um vetor de tamanho $N$. Tente criar uma solução $O(N \log N)$ e uma solução $O(N^2)$.

---

## 🏁 Links para Prática em Sites de Maratona de Programação

Praticar nesses ambientes afia a lógica e o rigor com tempo e memória de execução.

### Plataformas com Problemas Relevantes:

1. **Beecrowd (antigo URI)** - [beecrowd.com.br](https://www.beecrowd.com.br/judge/pt/)
* **1259 - Pares e Ímpares:** Clássico para treinar `sort` com função de comparação customizada.
* **1548 - Fila do Recreio:** Prática de cópia de arrays dinâmicos e ordenação simples.
* **1244 - Ordenação por Tamanho:** Exige ordenar structs baseando-se no tamanho da string.


2. **Codeforces** - [codeforces.com](https://codeforces.com/)
* Procure pelos problemas:
* 450B - Jzzhu and Sequences (ponteiros e regras modulares).
* 1367B - Even Array (ordenação e paridade).




3. **LeetCode** - [leetcode.com](https://leetcode.com/)
* Problemas clássicos:
* 56 - Merge Intervals (ordenação de structs baseada no primeiro eixo x).
* 253 - Meeting Rooms II (ordenamento com condições múltiplas).





Lembre-se: O segredo para dominar algoritmos avançados é a prática constante. Desenhe a alocação de memória no papel antes de ir para o código!


