# Matrizes

# Desvendando as Matrizes

Imagine um prédio de apartamentos ou uma planilha do Excel. Para encontrar uma informação específica, você precisa de duas coordenadas: a **Linha** e a **Coluna**. Na programação e na matemática, essa estrutura é chamada de **Matriz**.

Tecnicamente, uma matriz é um "vetor de vetores".
* Um **vetor** comum (`vet[x]`) é uma linha única de caixinhas.
* Uma **matriz** (`mat[x][y]`) é uma tabela inteira, onde cada linha contém várias colunas.

### Como declarar em C++
Para criar uma matriz de números inteiros com 3 linhas e 2 colunas:

```cpp
// Sintaxe: tipo nome[linhas][colunas];
int matriz_inteiros[3][2];
```
Nessa representação a matriz_inteiros possui 3 linhas e 2 colunas em cada linha podendo ser representada pelo desenho esquemático:

$$
\begin{array}{cc}
   % Espaço vazio no topo esquerdo e Rótulos das Colunas
   & \begin{matrix} \text{col 0}  & \text{col 1}  \end{matrix} \\
   % Rótulos das Linhas (lado esquerdo)
   \begin{matrix} 
      \text{linha 0 } \to \\
      \text{linha 1 } \to \\
      \text{linha 2 } \to 
   \end{matrix} &
   % A Matriz (lado direito)
   \begin{bmatrix} 
      1   &   2 \\ 
      5   &   6 \\
      0   &   9 
   \end{bmatrix}
\end{array}
$$

## Acessando elementos da matriz

Para acessar um elemento da matriz em C++ fazemos da seguinte forma:

```cpp
int elemento_da_matriz_acessado = matriz[i][j];

```
O **i** e o **j** indicam a posição do elemento que queremos acessar, como a matriz é um tipo de dados de duas dimensões temos que passar a linha (i) e coluna(j) onde o elemento está armazenado na memória.

Podemos acessar também diretamente o elemento usando literais:

```cpp
int elemento_da_matriz_acessado = matriz[2][1];

```
## Imprimindo uma matriz em C++

```cpp

// declaração da matriz

int matriz[3][3] = {{1,0,0},{0,1,0},{0,0,1}}; // matriz identidade

for ( int i = 0; i < 3; i++ ){ // primeiro laço for vai iterar sobre as linhas variando de 0 até 2
    for ( int j = 0; j < 3; j++ ){ // segundo laço for vai iterar sobre as colunas de cada linha de 0 até 2
        cout << matriz[i][j] << " "; // impressão da matriz com elementos separados por espaço
    }
    cout << endl; // salta uma linha após a iteração do loop interno
}
```

## Adição de Matrizes
A soma de duas matrizes, A e B, resulta em uma terceira matriz, C, onde cada elemento de C é a soma dos elementos correspondentes em A e B.

$$
\begin{bmatrix} 
a & b \\
c & d
\end{bmatrix} +
\begin{bmatrix} 
e & f \\
g & h
\end{bmatrix} =
\begin{bmatrix} 
a+e & b+f \\
c+g & d+h
\end{bmatrix}
$$

### Exemplo em C++
```cpp
#include <iostream>

using namespace std;

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2];

    // Somando as matrizes
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Imprimindo a matriz resultante
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

## Subtração de Matrizes
A subtração de duas matrizes, A e B, resulta em uma terceira matriz, C, onde cada elemento de C é a subtração dos elementos correspondentes em A e B.

$$
\begin{bmatrix} 
a & b \\
c & d
\end{bmatrix} -
\begin{bmatrix} 
e & f \\
g & h
\end{bmatrix} =
\begin{bmatrix} 
a-e & b-f \\
c-g & d-h
\end{bmatrix}
$$

### Exemplo em C++
```cpp
#include <iostream>

using namespace std;

int main() {
    int A[2][2] = {{8, 7}, {6, 5}};
    int B[2][2] = {{1, 2}, {3, 4}};
    int C[2][2];

    // Subtraindo as matrizes
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    // Imprimindo a matriz resultante
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

## Multiplicação de Matrizes
A multiplicação de matrizes é um pouco mais complexa. O elemento na linha *i* e coluna *j* da matriz resultante é a soma dos produtos dos elementos da linha *i* da primeira matriz com os elementos da coluna *j* da segunda matriz.

$$
\begin{bmatrix} 
a & b \\
c & d
\end{bmatrix} \times
\begin{bmatrix} 
e & f \\
g & h
\end{bmatrix} =
\begin{bmatrix} 
(a \times e) + (b \times g) & (a \times f) + (b \times h) \\
(c \times e) + (d \times g) & (c \times f) + (d \times h)
\end{bmatrix}
$$

### Exemplo em C++
Para um exemplo de código em C++, veja o arquivo [multiplicacao.cpp](multiplicacao.cpp).

### Exercícios Resolvidos do 1 a 4 - Atenção exercício 4 tem um desafio a ser lido e feito nos comentários

|  Exercício  |  link  |
| :---        | :---   |
|  **Ex01**       |        |
|  **Ex02**       |        |
|  **Ex03**       |        |
|  **Ex04**       |        |


