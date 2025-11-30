#include <bits/stdc++.h>

using namespace std;

int main() {
    int A = 0, B = 0;
    int N;
    int aux; 

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> aux;

        if (aux == 1) {
            // Apenas A inverte
            A = 1 - A; 
        }

        if (aux == 2) {
            // A inverte E B inverte também
            A = 1 - A;
            B = 1 - B;
        }
    }

    cout << A << endl; 
    cout << B << endl; 

    return 0;
}
