#include <bits/stdc++.h>

using namespace std;

int main() {
    // 1. Declaração da matriz 3x3
    vector<vector<int>> matriz = {
        {2, 3, 1},
        {5, 1, 4},
        {2, 2, 3}
    };

    cout << "--- MATRIZ INICIAL ---" << endl;
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[0].size(); j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // ---------------------------------------------------------
    // NOVA PARTE: ALTERAR ELEMENTO EM POSIÇÃO ESPECÍFICA
    // ---------------------------------------------------------
    int linhaUser, colUser, valorUser;

    cout << ">> ALTERAR UM ELEMENTO <<" << endl;
    
    // O usuário digita a linha (lembrando que para ele começa em 0 ou 1, aqui assumimos 0)
    cout << "Digite o indice da linha (0 a 2): ";
    cin >> linhaUser;
    
    cout << "Digite o indice da coluna (0 a 2): ";
    cin >> colUser;
    
    cout << "Digite o novo valor: ";
    cin >> valorUser;

    // Verificação de segurança para o programa não fechar se o usuário digitar errado
    if (linhaUser >= 0 && linhaUser < matriz.size() && 
        colUser >= 0 && colUser < matriz[0].size()) {
        
        // AQUI ACONTECE A TROCA
        matriz[linhaUser][colUser] = valorUser;
        cout << "Elemento alterado com sucesso!" << endl;
        
    } else {
        cout << "Erro: Indices invalidos! A matriz permaneceu igual." << endl;
    }
    cout << endl;

    cout << "--- MATRIZ ATUALIZADA ---" << endl;
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[0].size(); j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // ---------------------------------------------------------
    // ADICIONAR LINHA NO INÍCIO (Exemplo solicitado anteriormente)
    // ---------------------------------------------------------
    vector<int> novaLinha = {9, 9, 9};
    matriz.insert(matriz.begin(), novaLinha);
    
    // Remover logo em seguida para não estragar o cálculo do determinante 3x3 abaixo
    // (Apenas demonstrando que o código existe)
    matriz.erase(matriz.begin()); 


    // ---------------------------------------------------------
    // CALCULAR DETERMINANTE (Regra para 3x3)
    // ---------------------------------------------------------
    double det = 0;
    
    double t1 = matriz[0][0] * ((matriz[1][1] * matriz[2][2]) - (matriz[1][2] * matriz[2][1]));
    double t2 = matriz[0][1] * ((matriz[1][0] * matriz[2][2]) - (matriz[1][2] * matriz[2][0]));
    double t3 = matriz[0][2] * ((matriz[1][0] * matriz[2][1]) - (matriz[1][1] * matriz[2][0]));
    
    det = t1 - t2 + t3;

    cout << "--- RESULTADOS ---" << endl;
    cout << "Determinante: " << det << endl;

    // ---------------------------------------------------------
    // CALCULAR MATRIZ INVERSA
    // ---------------------------------------------------------
    cout << "Matriz Inversa:" << endl;

    if (det == 0) {
        cout << "Nao existe inversa (Determinante e zero)." << endl;
    } else {
        double invDet = 1.0 / det;
        cout << fixed << setprecision(2); 

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Indices auxiliares para a transposta dos cofatores
                int x1 = (i + 1) % 3;
                int x2 = (i + 2) % 3;
                int y1 = (j + 1) % 3;
                int y2 = (j + 2) % 3;
                
                double valor = (matriz[y1][x1] * matriz[y2][x2]) - (matriz[y1][x2] * matriz[y2][x1]);
                cout << valor * invDet << "\t";
            }
            cout << endl;
        }
    }

    return 0;
}
