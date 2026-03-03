#include <bits/stdc++.h>

using namespace std;

struct Aluno {
    string nome;
    int matricula;
    vector <float> notas;
};

int main() {
    int n;
    cin >> n;
    int v[n]; // tamanho do vetor
    for ( int i =0 ; i < n; i++){
        cin >> v[i];
    }
    
    sort(v,v+1 );
    
    for ( int i = 0 ; i < n; i++ ) {
        cout << v[i] << "  "  ;
    }
    cout << "\n";




	return 0;
}
