## 🛠️ Funções em C++

As funções ajudam o nosso código a ficar mais limpo, organizado e reaproveitável. Futuramente, vocês aprenderão a utilizar esse recurso em conjunto com diversas bibliotecas.

Devemos lembrar que, na verdade, nós já usamos funções o tempo todo, sendo o exemplo mais prático a nossa famosa função principal: `int main() {}`

Toda função em C++ tem o seguinte formato básico:

```cpp
TIPO_DA_FUNCAO NOME_DA_FUNCAO ( PARAMETROS DA FUNCAO ) { 
    // CÓDIGO A SER EXECUTADO (CORPO DA FUNÇÃO)
    // RETORNO DA FUNÇÃO (SE NECESSÁRIO)
}

```

**Regra de Ouro:** O retorno da função deve acompanhar o seu tipo. Ou seja, se a função é do tipo `int`, seu retorno deve ser `int`; se for `string`, o retorno deve ser `string`, e assim por diante.

* **A Exceção (`void`):** Quando uma função é do tipo `void` (vazio), ela **não tem retorno**. Ela serve apenas para executar uma ação, como imprimir algo na tela.

### Exemplo Prático: Unindo `struct` e Funções (Sistema de IMC)

Veja como podemos criar funções separadas para ler dados e fazer cálculos, deixando a `main` muito mais limpa:

```cpp
#include <bits/stdc++.h>
using namespace std;

// Definindo a nossa estrutura de dados
struct info_pessoa {
    string nome;
    int idade;
    double peso;
    double altura;
};

// Função que recebe uma struct, preenche os dados pelo teclado e a retorna
info_pessoa entrada_dados_pessoais(info_pessoa pessoa) {
    cout << "Digite nome da pessoa -> ";
    cin >> pessoa.nome;
    
    cout << "Digite idade da pessoa -> ";
    cin >> pessoa.idade;
    
    cout << "Digite peso da pessoa -> ";
    cin >> pessoa.peso;
    
    cout << "Digite altura da pessoa -> ";
    cin >> pessoa.altura;
    
    return pessoa; // Retorna a struct preenchida
}

// Função para calcular o IMC (Independente da struct)
double calcular_imc(double peso, double altura) {
    return peso / (altura * altura);
}

int main() {
    info_pessoa aluno;

    cout << "--- SISTEMA DE CADASTRO E IMC ---\n";

    // O retorno da função vai preencher a variável 'aluno'
    aluno = entrada_dados_pessoais(aluno);

    // Chamamos a função de IMC passando os atributos específicos
    double imc_resultado = calcular_imc(aluno.peso, aluno.altura);

    cout << "\n--- RESULTADO ---\n";
    cout << "Nome: " << aluno.nome << "\n";
    cout << "Idade: " << aluno.idade << " anos\n";
    cout << "IMC Calculado: " << imc_resultado << "\n";

    return 0;
}

```

---

## 🔄 Funções Recursivas

A recursão ocorre quando uma função invoca a si mesma dentro do seu próprio código. É uma técnica essencial em programação competitiva para resolver problemas que podem ser divididos em problemas menores iguais.

Toda função recursiva precisa obrigatoriamente de duas coisas para não rodar infinitamente e travar o computador:

1. **Caso Base:** A condição de parada. É o cenário mais simples possível que a função sabe resolver sem chamar a si mesma.
2. **Passo Recursivo:** A lógica que quebra o problema e faz a nova chamada caminhando em direção ao caso base.

---

## 💻 Material da aula

* **[Funções.pdf](../../) ** Material de Funções
* **[Resolução Função , Struct](../../) ** Resolução de exercícios
* **[Exercícios] (../../) ** Exercícios

## 🥊 A Grande Disputa: `std::pair` vs `struct`

Tanto `pair` quanto `struct` servem para agrupar dados, mas usamos cada um em situações diferentes:

### `std::pair` (O Rápido e Simples)

Agrupa exatamente **dois** valores (que podem ser de tipos diferentes), acessados por `.first` e `.second`.

* **Quando usar:** Em competições, quando precisamos retornar dois valores de uma função rapidamente ou ao agrupar dados simples onde a ordem e a velocidade de digitação importam mais que o nome das variáveis. O `pair` já sabe se comparar automaticamente (útil no `sort()`).
* **Quando NÃO usar:** Quando você precisa de 3 ou mais dados, ou quando chamar de `.first` deixar o código confuso.

### `struct` (A Planta Baixa)

Cria um **tipo de dado customizado**, onde você dá nome a cada variável (ex: `.idade`, `.peso`).

* **Quando usar:** Quando modelamos entidades reais com múltiplos atributos (ex: `Atleta`, `Carro`, `Ponto3D`). Deixa o código extremamente legível e organizado.
* **Quando NÃO usar:** Se for só para retornar dois números aleatórios de uma função rápida.

---

## 💻 Exercícios Práticos (Neps Academy)

Para fixar o conteúdo da aula, resolvam os seguintes problemas no Neps Academy:

### 1. Treinando Funções Básicas

* **[Problema 27 - Primo](https://neps.academy/br/exercise/27):** Isole a lógica matemática em uma função.
* **[Problema 169 - Fórmula de Bhaskara](https://neps.academy/br/exercise/169):** Pratique passar múltiplos parâmetros.

### 2. Desafios de Recursão

* **[Problema 173 - Fibonacci](https://neps.academy/br/exercise/173):** Implemente a versão recursiva para entender a árvore de chamadas.
* **[Problema 107 - Torre de Hanói](https://neps.academy/br/exercise/107):** O clássico absoluto para dominar a recursão.

### 3. Organização de Dados (`pair` e `struct`)

* **[Problema 160 - Ordenação Simples](https://neps.academy/br/exercise/160):** Resolva usando vetores normais e tente adaptar usando `std::pair`.
* **[Problema 243 - Olimpíadas](https://neps.academy/br/exercise/243):** O desafio final. Crie uma `struct` para os países, armazene as medalhas e utilize uma função de comparação (comparator) para ordenar corretamente.
