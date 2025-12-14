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

