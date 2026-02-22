#include <bits/stdc++.h>

using namespace std;

// Função 1: Responsável apenas pela entrada de dados
vector<int> entrada_dados() {
    int n;
    cin >> n;
    
    vector<int> valores(n);
    for (int i = 0; i < n; ++i) {
        cin >> valores[i];
    }
    
    return valores;
}

// Função 2: Responsável pela lógica de contagem
int contar_consecutivos(const vector<int>& valores) {
    if (valores.empty()) {
        return 0;
    }

    int max_consecutivos = 1;
    int contagem_atual = 1;

    // Percorre o vetor a partir do segundo elemento
    for (size_t i = 1; i < valores.size(); ++i) {
        if (valores[i] == valores[i - 1]) {
            // Se for igual ao anterior, a sequência continua
            contagem_atual++;
        } else {
            // Se mudou, atualiza o máximo (se necessário) e reseta a contagem
            if (contagem_atual > max_consecutivos) {
                max_consecutivos = contagem_atual;
            }
            contagem_atual = 1;
        }
    }
    
    // Verificação final caso a maior sequência esteja no final do vetor
    if (contagem_atual > max_consecutivos) {
        max_consecutivos = contagem_atual;
    }

    return max_consecutivos;
}

// Função 3: A função principal que orquestra o programa
int main() {
    // Otimização padrão para acelerar entrada e saída no C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Chama a função de entrada
    vector<int> dados = entrada_dados();

    // Chama a função de processamento
    int resultado = contar_consecutivos(dados);

    // Imprime a saída
    cout << resultado << "\n";

    return 0;
}
