#include<bits/stdc++.h>

using namespace std;

int main() {
    int tam1, tam2;

    cout << "Entre o tamanho da primeira e segunda matriz: ";
    cin >> tam1 >> tam2;

    if (tam1 != tam2) {
        cout << "Erro: As matrizes devem ter o mesmo tamanho para esta operacao." << endl;
        return 1;
    }

    int tam = tam1;
    int matriz1[tam][tam];
    int matriz2[tam][tam];
    int res[tam][tam]; // a opção res[tam][tam] = {{0}}; não funciona adequadamente em c++ 20

    // Leitura da Matriz 1
    cout << "\n--- Digite os valores da Matriz 1 ---\n";
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            cout << "Matriz1 [" << i << "][" << j << "]: ";
            cin >> matriz1[i][j];
        }
    }

    // Leitura da Matriz 2
    cout << "\n--- Digite os valores da Matriz 2 ---\n";
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            cout << "Matriz2 [" << i << "][" << j << "]: ";
            cin >> matriz2[i][j];
        }
    }

    // Exibição Lado a Lado
    cout << "\n--- Visualizacao ---\n\n";
    for (int i = 0; i < tam; i++) {
        
        // Imprime linha da Matriz 1
        for (int j = 0; j < tam; j++) {
            cout << setw(5) << matriz1[i][j] << " ";
        }

        // Imprime separador
        if (i == tam / 2) 
            cout << "   X   ";
        else 
            cout << "       ";

        // Imprime linha da Matriz 2
        for (int j = 0; j < tam; j++) {
            cout << setw(5) << matriz2[i][j] << " ";
        }
        
        cout << endl;
    }
    cout << endl;
    // Multiplicação de matriz1 x matriz2
    cout << "\tMULTIPLICAÇÃO DAS MATRIZES\n" << endl;
    for ( int i = 0; i < tam; i++ ){
        for ( int j =0; j < tam; j++ ) {
            res[i][j] = 0; // garante que a matriz resultado tem todos os seus valores como zero
            for ( int k = 0; k < tam; k++ ) {
                res[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    // mostra o resultado na tela
    for ( int i = 0; i < tam; i++ ) {
        for ( int j = 0; j < tam; j++ ) {
            cout << setw(5) << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
