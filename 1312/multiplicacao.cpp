#include <bits/stdc++.h>
using namespace std;

int main() {
    // declaração das matrizes mat, x e res 
    int mat[2][2] = { {1,2}, {3,4} };
    int x[2][2] = { {5,6}, {7,8} };
    int res[2][2] = {0}; // Inicializa a matriz resultado com zeros

    // Método 1: Multiplicação manual das matrizes 
    res[0][0] = (mat[0][0] * x[0][0]) + (mat[0][1] * x[1][0]);
    res[1][0] = (mat[1][0] * x[0][0]) + (mat[1][1] * x[1][0]);
    res[0][1] = (mat[0][0] * x[0][1]) + (mat[0][1] * x[1][1]);
    res[1][1] = (mat[1][0] * x[0][1]) + (mat[1][1] * x[1][1]);

    cout << "Resultado da multiplicação manual:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    // Reset da matriz resultado para o método com loops
    int res2[2][2] = {0}; // Nova matriz para evitar sobreposição

    // Método 2: Multiplicação com loops
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) { // como vimos existe uma inversão nos valores de i e j , daí a necessidade do k 
                // observem as linhas 11 a 14 e vejam a necessidade do k em relação ao i e j.
                res2[i][j] += mat[i][k] * x[k][j];
            }
        }
    }

    cout << "\nResultado da multiplicação com loops:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << res2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
