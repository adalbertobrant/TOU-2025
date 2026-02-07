#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    
    // Converter para minúsculas e remover espaços
    for (char &c : a) {
        if (c >= 'A' && c <= 'Z') c += 32;
        if (c == ' ') c = '\0';  // Remove espaços
    }
    for (char &c : b) {
        if (c >= 'A' && c <= 'Z') c += 32;
        if (c == ' ') c = '\0';
    }
    
    // Ordenar as strings
    sort(a.begin(), a.end());
    sort(b.begin(), b.end()); // sort(inicio, fim )
    
    // Remover caracteres nulos após ordenação (espaços removidos)
    a.erase(remove(a.begin(), a.end(), '\0'), a.end());
    b.erase(remove(b.begin(), b.end(), '\0'), b.end());
    
    if (a == b) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }
    
    return 0;
}
