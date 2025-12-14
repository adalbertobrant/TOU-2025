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

C
O **i** e o **j** indicam a posição do elemento que queremos acessar, como a matriz é um tipo de dados de duas dimensões temos que passar a linha (i) e coluna(j) onde o elemento está armazenado na memória.

Podemos acessar também diretamente o elemento usando literais:
```cpp
int elemento_da_matriz_acessado = matriz[2][1];
```
Como podemos observar existe uma pequena similaridade entre o conceito matemático de matrizes e como a mesma é imaginada em circuitos de memória dentro do computador.

As matrizes são armazenadas na memória como longos vetores e são utilizadas como uma forma de guardar dados, realizar cálculos matemáticos complexos, tais como a multiplicação de matrizes, abaixo vamos desenvolver um passo a passo de como calcular a soma, divisão, multiplicação e subtração de matrizes na matemática para depois implementarmos isso com código:




  
