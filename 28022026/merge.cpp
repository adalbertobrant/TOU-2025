#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;
int v[MAX], aux[MAX];

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
    int n = 200; // quantidade de elementos

    srand(time(0)); // inicializa a semente do aleatório

    // Preenche o vetor com números aleatórios
    for (int i = 1; i <= n; i++) {
        v[i] = rand() % 10000;
    }

    // cópia do vetor v[i] existente 
    // 

    cout << "Vetor original:\n";
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";

    // Comparar o tempo 

    clock_t t_inicio = clock();

    mergesort(1, n);

    clock_t t_fim = clock();

//  Fazer a ordenação usando o sort 
//
//  colocar um vetor do mesmo tamanho de n
//  clock_t inicio_sort;
//  sort ();
//  clock_t fim_sort;
//
    

    cout << "\n\nVetor ordenado:\n";
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";

    cout << endl;

    // Tempo de execução do merge sort
    double tempo_segundos = (double)(t_fim - t_inicio) / CLOCKS_PER_SEC;
  // double tempo_segundos_sort
  
    cout << "Tempo de execucao MERGE SORT: " << tempo_segundos << " segundos" << endl;

    // Existe uma diferença de tempo entre o merge sort e o sort
    //
    // cout<<< tempo de execução do Sort 
    return 0;
}
