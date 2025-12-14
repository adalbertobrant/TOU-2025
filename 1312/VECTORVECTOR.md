#include <vector>
using namespace std;

// Declaração de um vetor de vetores
vector<vector<int>> matriz;

int linhas = 5;
int colunas = 3;
int valorInicial = 0;

// Cria o vetor 'matriz' com 'linhas' elementos.
// Cada elemento é um vector<int> de tamanho 'colunas', preenchido com 'valorInicial'.
vector<vector<int>> matriz(linhas, vector<int>(colunas, valorInicial));

## Função backtracking 

### Algumas vezes em programação precisamos voltar atrás e refazer um determinado caminho, como no caso a seguir:
2. O que é Backtracking?
Backtracking é uma técnica de tentativa e erro inteligente. Imagine que você está num labirinto:

Você escolhe um caminho e segue.

Se der de cara com uma parede (ou beco sem saída), você volta (backtrack) até o último cruzamento.

Escolhe uma opção diferente e tenta de novo.

Em programação, usamos recursão (uma função que chama a si mesma) para fazer isso.

```c++
bool resolver(int x, int y, vector<vector<int>>& matriz) {
    // 1. CASO BASE (Parada ruim):
    // Se saiu dos limites da matriz ou bateu numa parede/obstáculo.
    if (x < 0 || y < 0 || x >= linhas || y >= colunas || matriz[x][y] == PAREDE) {
        return false;
    }

    // 2. CASO BASE (Sucesso):
    // Se chegamos no objetivo.
    if (matriz[x][y] == FIM) {
        return true;
    }

    // 3. MARCAR (Visitado):
    // Marca a posição atual para não voltarmos nela num loop infinito.
    matriz[x][y] = VISITADO;

    // 4. RECURSÃO (Tentar vizinhos):
    // Tenta ir para baixo, cima, direita, esquerda.
    if (resolver(x + 1, y, matriz) == true) return true; // Baixo
    if (resolver(x - 1, y, matriz) == true) return true; // Cima
    if (resolver(x, y + 1, matriz) == true) return true; // Direita
    if (resolver(x, y - 1, matriz) == true) return true; // Esquerda

    // 5. BACKTRACK (Desfazer):
    // Se nenhum vizinho deu certo, desmarcamos a posição atual
    // (pois ela não faz parte da solução) e retornamos falso para quem chamou.
    matriz[x][y] = LIVRE; // Ou deixa como visitado se não quiser passar lá nunca mais

    return false;
}
```
## Exemplo do Robot no labirinto
```c++
#include <iostream>
#include <vector>

using namespace std;

// Função auxiliar para imprimir a solução
void imprimirMatriz(const vector<vector<int>>& m) {
    for (const auto& linha : m) {
        for (int val : linha) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Nossas dimensões
int N = 4;

// Função de Backtracking
bool acharCaminho(int x, int y, vector<vector<int>>& labirinto, vector<vector<int>>& solucao) {
    // 1. Checar limites e se é parede (0)
    if (x < 0 || x >= N || y < 0 || y >= N || labirinto[x][y] == 0) {
        return false;
    }

    // 2. Checar se chegamos ao destino (canto inferior direito)
    if (x == N - 1 && y == N - 1) {
        solucao[x][y] = 1; // Marca o fim
        return true;
    }

    // 3. Verificar se já passamos aqui (para evitar loops)
    if (solucao[x][y] == 1) {
        return false;
    }

    // --- Passo da ESCOLHA ---
    // Marca este caminho como parte da solução temporária
    solucao[x][y] = 1;

    // --- Passo da RECURSÃO (Tenta mover Baixo e Direita) ---
    // (Neste exemplo simples vamos tentar só duas direções para facilitar)

    if (acharCaminho(x + 1, y, labirinto, solucao)) return true; // Tenta Baixo
    if (acharCaminho(x, y + 1, labirinto, solucao)) return true; // Tenta Direita

    // --- Passo do BACKTRACKING (Desfazer) ---
    // Se chegou aqui, nem baixo nem direita deram certo.
    // Então este quadrado (x, y) não serve. Desmarcamos ele.
    solucao[x][y] = 0;

    return false;
}

int main() {
    // 1 = Caminho livre, 0 = Parede
    vector<vector<int>> labirinto = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    // Matriz para guardar o caminho da solução (tudo zero inicialmente)
    vector<vector<int>> solucao(N, vector<int>(N, 0));

    if (acharCaminho(0, 0, labirinto, solucao)) {
        cout << "Caminho encontrado:\n";
        imprimirMatriz(solucao);
    } else {
        cout << "Sem solucao";
    }

    return 0;
}
```
## Resumo
Resumo para o seu estudo:
Vetor de Vetor: É apenas uma lista onde cada linha é outra lista. Use vector<vector<tipo>>.

Recursão: A função chama ela mesma para o "próximo passo" (vizinho).

Estado: Você precisa saber onde está (x, y) e o que já visitou.

Desfazer (Backtrack): Se a recursão voltar dizendo "não deu certo", você desfaz a sua mudança atual na matriz e retorna falso também.

