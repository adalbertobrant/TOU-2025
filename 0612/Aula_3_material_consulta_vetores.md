Aula 3: Material de Consulta - Vetores
1. O que são Vetores?
São estruturas de dados que permitem armazenar uma sequência de elementos do mesmo tipo em uma única variável. Eles são usados para organizar e manipular coleções de dados de forma eficiente, sendo conhecidos como arrays, arranjos ou sequências.
+1

2. Tipos de Vetores em C++
É importante distinguir entre o "vetor estilo C" (array estático) e o "vetor do C++" (std::vector).

A. Vetor Estático (Array Simples)
São declarados com um tamanho fixo, definido no momento da compilação. O tamanho não pode ser alterado durante a execução.

Exemplo:

C++

#include <iostream>
using namespace std;

int main() {
    // Declara um vetor de 5 posições fixas
    int vetor[5] = {10, 20, 30, 40, 50}; 
    return 0;
}
B. Vetor Dinâmico (std::vector)
No C++, utilizamos a biblioteca <vector>. Estes são vetores que podem crescer ou diminuir de tamanho automaticamente conforme elementos são adicionados ou removidos. Atenção: As funções listadas abaixo (push_back, size, etc.) funcionam apenas neste tipo.

Exemplo:

C++

#include <iostream>
#include <vector> // Necessário incluir esta biblioteca
using namespace std;

int main() {
    // Declara um vetor dinâmico vazio (tamanho inicial 0)
    vector<int> meuVetor; 
    
    // Adiciona elementos dinamicamente
    meuVetor.push_back(10); // Agora tem tamanho 1
    meuVetor.push_back(20); // Agora tem tamanho 2
    
    return 0;
}
3. Principais Funções e Algoritmos
Para manipular vetores dinâmicos (vector), utilizamos métodos próprios e funções da biblioteca <algorithm>.

Métodos do Vetor (Membros da classe)

vet.push_back(valor): Insere um elemento ao final do vetor.

vet.pop_back(): Remove o último elemento do vetor.


vet.at(i): Retorna o valor na posição i com verificação de segurança. (Similar a vet[i]).


vet.size(): Retorna a quantidade atual de elementos no vetor.


vet.begin() e vet.end(): Retornam iteradores apontando, respectivamente, para o início e para o "fim teórico" (após o último elemento) do vetor. Essenciais para usar com algoritmos de ordenação e busca.

Algoritmos Úteis (Requer #include <algorithm>)
Aqui estava o erro principal do seu PDF original. Estas não são funções do vetor ("vet."), mas sim funções globais que operam sobre o vetor.


reverse(vet.begin(), vet.end()): Inverte a ordem dos elementos do vetor.

Exemplo: {1, 2, 3} vira {3, 2, 1}.

count(vet.begin(), vet.end(), valor): Retorna a quantidade de vezes que o valor aparece no vetor.

Correção: No PDF original estava escrito cout (que serve para imprimir na tela). O correto é count (contar).

sort(vet.begin(), vet.end()): Ordena o vetor em ordem crescente.

4. Resumo e Dicas

Utilidade: Vetores são ideais para organizar, procurar e listar dados, sendo muito usados em jogos, cadastros e processamento de dados.


Pré-requisitos: Para dominar vetores, tenha uma base sólida em laços de repetição (for, while), pois são usados para percorrer o vetor.


Prática: Use as funções prontas (push_back, size, sort) para facilitar seu código e evitar reinventar a roda.


Interpretação: Antes de codificar, leia o enunciado e decida se você precisa de um tamanho fixo (array) ou se a quantidade de dados pode mudar (vector)

5. Material Complementar acesse abaixo
   ![Código Exemplo](https://github.com/adalbertobrant/TOU-2025/blob/main/0612/material_complementar_vector.cpp)
   
