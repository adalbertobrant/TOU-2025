#include <bits/stdc++.h>

using namespace std;


int main() {

    // declaração de uma matriz utilizando vector
    vector < vector <int> > matriz = {{2,3,3,3},{5,3,3,4}};
    
    int linhasVetor = matriz.size();
    cout << linhasVetor << endl;
    
    int colunasVetor = matriz[0].size();
    cout << colunasVetor << endl;

    // adicionar um elemento ao vector<vector<int>> matriz em sua coluna
    for ( int i = 0; i < 2; i++){
        matriz[i].push_back(i*11109);
    }
    // adicionar linhas 
    for ( int i = 0; i < 2; i++ ){
        matriz.push_back({i*100});
    }

    // mostrar na tela 
    for ( int i = 0 ; i < matriz.size(); i++ ){
        for ( int j = 0; j < matriz[0].size(); j++ ){
            cout << matriz[i][j] << " " ;
        }
        cout << endl;
    }



	return 0;
}
