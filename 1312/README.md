# Matrizes

Matrizes são vetores de vetores ou seja para cada posição de um vetor do tipo vet[n], temos que em vet[n-n] ou seja vet[0] uma posicao que dentro dela temos um novo vetor x[k] onde k pode ser ou não do mesmo tamanho de n, não sendo entretanto necessário.

Podemos declarar então uma matriz em C++ como:
```c++
// matriz de inteiros em C++
int matriz_inteiros[3][2]
````
Nessa representação a matriz_inteiros possui 3 linhas e 2 colunas em cada linha podendo ser representada pelo desenho esquemático:

$$
\begin{array}{cc}
   % Espaço vazio no topo esquerdo e Rótulos das Colunas
   & \begin{matrix} \text{col 0}  & \text{col 1}  \end{matrix} \\
   % Rótulos das Linhas (lado esquerdo)
   \begin{matrix} 
      \text{linha 0} \to \\\\ 
      \text{linha 1} \to \\\\ 
      \text{linha 2} \to 
   \end{matrix} &
   % A Matriz (lado direito)
   \begin{bmatrix} 
      1 & 2 \\\\ 
      5 & 6 \\\\ 
      0 & 9 
   \end{bmatrix}
\end{array}
$$
  
