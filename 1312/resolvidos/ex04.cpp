#include <bits/stdc++.h>

using namespace std;

// ler do teclado e calcular a média

int main() {

    int tam_linhas = 0;
    int tam_colunas = 0;
    double somador = 0;
    double media = 0;
    
    cout << "Entre a quantidade de linhas da matriz -> "; 
    cin >> tam_linhas;

    cout << "Entre a quantidade de colunas da matriz -> ";
    cin >> tam_colunas;

    int matriz[tam_linhas][tam_colunas];

    // Entra com os dados da matriz no teclado
    for ( int i =0; i < tam_linhas; i++ ){
        for ( int j = 0; j < tam_colunas; j++ ){
            printf("Entre o valor do %d° elemento da matriz[%d][%d] na posição matriz[%d][%d] -> ", (i*tam_colunas) +j + 1,tam_linhas,tam_colunas,i,j);
            cin >> matriz[i][j];
            // aqui você pode colocar um somador
            somador += matriz[i][j];
        }
    }

    media = somador / (tam_linhas * tam_colunas); // faz o cálculo da média
    
    cout << format("A média da matriz[{}][{}] com {} elementos é {:.2f}", tam_linhas, tam_colunas, tam_linhas * tam_colunas, media) << endl;

    // tarefa fazer aqui a distância absoluta (abs)  de cada elemento da média usando a seguinte formula:
    // d = | elemento - media |
    // Colocar em uma nova matriz


	return 0;
}

