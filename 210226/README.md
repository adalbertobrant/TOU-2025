# Funções

As funções ajudam o nosso código a ficar mais limpo e organizado. Futuramente, vocês aprenderão a utilizar esse recurso junto com as bibliotecas.

Devemos lembrar que, na verdade, nós já usamos funções o tempo todo, sendo o exemplo mais prático a nossa famosa função principal: int main( ) { }

Toda função em C / C++ tem o seguinte formato básico:

TIPO_DA_FUNÇÃO NOME_DA_FUNÇÃO ( PARÂMETROS DA FUNÇÃO ) {     CÓDIGO A SER EXECUTADO (CORPO DA FUNÇÃO)     RETORNO DA FUNÇÃO (SE NECESSÁRIO) }
```
  TipoDeRetorno nomeDaFuncao(TipoParametro1 param1, TipoParametro2 param2) {
    // Lógica interna da função
    return valor;
}
```
## Atenção: 
  O retorno da função deve acompanhar o seu tipo, ou seja se a função é do tipo int , seu retorno deve ser int, se string, seu retorno deve ser do tipo string e assim por diante.

## O tipo void:
  É uma função especial que não tem um retorno sendo normalmente utilizada com ponteiros, ou em alguns casos para a realização do casting, por enquanto é apenas uma observação mas é interessante saber mais para frente sobre o assunto.

## Retorno em uma função
  Para retorno de valores unitários já sabemos que nossa função irá retornar de acordo com o parâmetro da mesma, e se quisermos retornar na nossa função mais de um valor ?
  Se o retorno de valores necessários para a nossa função for do mesmo tipo podemos utilizar um vetor daquele mesmo tipo da função se inteiro , podemos retornar um vector <int> por exemplo.
  Mas e quando queremos retornar valores diferentes, como double, string, int em nossa função como podemos fazer isso ? Veja o exemplo a seguir:
  ```c++
#include <bits/stdc++.h>
using namespace std;

struct info_pessoa { // struct de determina informações de uma pessoa 
    string nome;
    int idade;
    double peso;
    double altura;
};

// Função que recebe uma struct, preenche os dados e a retorna
// Observe que o tipo de parâmetro da função é também uma struct

info_pessoa entrada_dados_pessoais(info_pessoa pessoa) {

    cout << "Digite nome da pessoa -> ";
    cin >> pessoa.nome;
    
    cout << "Digite idade da pessoa -> ";
    cin >> pessoa.idade; 
    
    cout << "Digite peso da pessoa -> "; 
    cin >> pessoa.peso; 
    
    cout << "Digite altura da pessoa -> "; 
    cin >> pessoa.altura; 
    
    return pessoa; // retorna a struct passada
}

// Função para calcular o IMC

double calcular_imc(double peso, double altura) {

    return peso / (altura * altura); 
}

int main() {

    // Aqui criamos uma varíavel do tipo struct info_pessoa

    info_pessoa aluno;

    cout << "--- SISTEMA DE CADASTRO E IMC ---\n";

    // 2. Chamamos a função para preencher os dados.  
    // O retorno da função vai sobrescrever a variável 'aluno'

    aluno = entrada_dados_pessoais(aluno);

    // 3. Chamamos a função de IMC, passando apenas os atributos necessários

    double imc_resultado = calcular_imc(aluno.peso, aluno.altura); 

    // Mostra o resultado na tela , aqui podemos criar uma função do tipo void para mostrar esse resultado
    // DESAFIO -> CRIE A FUNÇÃO VOID QUE MOSTRE O RESULTADO COM OS DADOS NOME DO PACIENTE, IDADE, IMC CALCULADO
    // void nome_função ( parâmtros da função ) { corpo da função } 

    cout << "\n--- RESULTADO ---\n";
    cout << "Nome do Paciente: " << aluno.nome << "\n";
    cout << "Idade: " << aluno.idade << " anos\n";
    cout << "IMC Calculado: " << imc_resultado << "\n";

    return 0;
}

```
  No exemplo acima observamos o poder da função associado a essa nova estrutura de dados chamada struct .

  Segue abaixo uma tabela com as diferenças entre Pair e Struct em C++ .

|  Característica     |  std::pair                                           |  struct                                                                  |
| --                  | --                                                   | --                                                                       |
| -- Acesso           | ".first, .second"                                    |  "Nomes definidos (ex: .idade, .pontos)"                                 |
| -- Semântica        |  Genérica (baixa clareza visual)                     |  Específica (alta clareza visual)                                        |
| -- Ordenação Padrão |  "Nativa (compara o primeiro, desempata no segundo)" |  Requer criação de um comparator ou sobrecarga do operador <             |
| -- Quantidade de Dados  |  Exatamente 2                                    | Quantos forem necessários                                                |

## Material dado em aula 


