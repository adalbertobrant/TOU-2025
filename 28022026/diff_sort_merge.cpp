#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;
int v[MAX], v_copia[MAX], aux[MAX];

void mergesort(int l, int r) {
    if (l == r) return;

    int m = (l + r) / 2;

    mergesort(l, m);
    mergesort(m + 1, r);

    int pos1 = l;
    int pos2 = m + 1;

    for (int i = l; i <= r; i++) {
        if (pos1 == m + 1)
            aux[i] = v[pos2++];
        else if (pos2 == r + 1)
            aux[i] = v[pos1++];
        else if (v[pos1] <= v[pos2])
            aux[i] = v[pos1++];
        else
            aux[i] = v[pos2++];
    }

    for (int i = l; i <= r; i++)
        v[i] = aux[i];
}

int main() {
    int n = 1000000; 

    srand(time(0)); 

    // Preenche o vetor com números aleatórios
    for (int i = 1; i <= n; i++) {
        v[i] = rand() % 10000;
        v_copia[i] = v[i]; 
    }

    // --- Medindo MERGE SORT ---
    clock_t t_inicio_merge = clock();
    mergesort(1, n);
    clock_t t_fim_merge = clock();

    // --- Medindo STD::SORT ---
    
    clock_t t_inicio_sort = clock();
    sort(v_copia + 1, v_copia + n + 1);
    clock_t t_fim_sort = clock();

    // Cálculo dos tempos
    double tempo_merge = (double)(t_fim_merge - t_inicio_merge) / CLOCKS_PER_SEC;
    double tempo_sort = (double)(t_fim_sort - t_inicio_sort) / CLOCKS_PER_SEC;

    cout << fixed << setprecision(6); // Formata para mostrar casas decimais
    cout << "Tempo de execucao MERGE SORT: " << tempo_merge << " segundos" << endl;
    cout << "Tempo de execucao STD::SORT:  " << tempo_sort << " segundos" << endl;

    // Comparação direta
    if (tempo_sort < tempo_merge) {
        cout << "\nO std::sort foi " << tempo_merge / tempo_sort << "x mais rapido que o seu Merge Sort." << endl;
    }

    return 0;
}
