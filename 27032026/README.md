# 📁 TOU - 2025 - Manipulação de Arquivos: Texto e Binário em C++

### ⌨️ Entrada de Dados: Além do Teclado

- A entrada de dados até agora foi feita apenas pelo teclado, e a nossa saída de dados foi sempre através da tela.
- Mas, e nos casos onde precisamos que a entrada seja o conteúdo de um pendrive que, depois de processado, deve ser enviado para o mesmo pendrive sem necessariamente passar por uma tela? 

```bash
    [Teclado] -> [Computador] -> [Tela]  # O que fazíamos
    [Arquivo.txt] -> [Computador] -> [Arquivo_Modificado.txt] # O que vamos fazer! 🚀
```

- Imagine se, no trabalho, tivéssemos que digitar manualmente os preços dos produtos do supermercado, passando para uma planilha de maneira manual... Existe uma perda de tempo colossal que não pode mais ser tolerada.
- Precisamos de soluções mais eficazes, rápidas e automatizadas. E é aí que entram os arquivos!

### 💾 O Arquivo

- Um arquivo é um conjunto de bits guardado em algum dispositivo de armazenamento permanente. Ex: Pen drive, SSD, HDD.
- Em um computador, quase tudo é representado por arquivos! Eles são operacionalizados desde o momento em que se liga o PC (o *bootloader* é um arquivo que chama o sistema operacional, etc).

### 🗂️ Tipos de Arquivo (Visão do Usuário)

Para o usuário comum, existem dezenas de tipos de arquivos, identificados por suas extensões:
* **Fotos:** `.jpeg`, `.bmp`, `.png`
* **Textos:** `.txt`, `.docx`, `.rtf`
* **Planilhas:** `.csv`, `.xlsx`
* **Vídeos & Áudio:** `.mp4`, `.avi`, `.mp3`, `.wav`
* **Códigos/Programas:** `.cpp`, `.py`, `.exe`

### 💻 Tipos de Arquivo (Visão do Programador C++)

Para nós, programadores, a vida é mais simples. Basicamente, dividimos tudo em dois grandes grupos: **Arquivos de Texto** e **Arquivos Binários**.

#### 📝 Arquivos de Texto
-> **Foco humano:** Uma pessoa consegue ler em linguagem natural se abrir em um bloco de notas.
-> A informação é guardada usando codificações de caracteres (onde, tradicionalmente, 8 bits = 1 caractere, como na tabela ASCII original).
-> **Padrão Moderno:** O **UTF-8** (Unicode Transformation Format) é o padrão global atual. Ele suporta múltiplos idiomas usando de 1 a 4 bytes por caractere, sendo totalmente compatível com os 128 caracteres básicos do ASCII. [Saiba mais sobre Unicode aqui](https://home.unicode.org/).

#### 🤖 Arquivos Binários
-> **Foco na máquina:** O computador consegue ler muito mais rápido. Se você tentar abrir num bloco de notas, verá um monte de "rabiscos" ilegíveis.
-> Uma sequência de bits onde a informação é salva na sua forma *nativa* da memória (um `int` de 4 bytes é salvo exatamente como esses 4 bytes, sem ser convertido para o texto "1234").
-> São menores, mais rápidos de ler/escrever e não precisam de caracteres especiais de formatação (como as quebras de linha `\n` entre números).

**Exemplo Prático (Salvando o número `0.3`):**
* **Arquivo Texto:** Precisamos salvar o caractere '0', o caractere '.', e o caractere '3'. (3 bytes no mínimo).
* **Arquivo Binário:** Salvamos direto os bits do padrão de ponto flutuante (sinal, expoente e mantissa). Não precisamos de um caractere de "ponto" (.) porque a estrutura binária já diz à máquina que aquilo é um decimal.

---



## 🛠️ Colocando a Mão na Massa: A Biblioteca `<fstream>`

No C++, para trabalhar com arquivos, precisamos incluir a biblioteca `<fstream>` (File Stream). Ela nos dá três ferramentas (classes) principais:

1.  **`ofstream`** (Output File Stream): Usado **apenas para escrever** em arquivos. (Pense no "o" como *out* / saída).
2.  **`ifstream`** (Input File Stream): Usado **apenas para ler** de arquivos. (Pense no "i" como *in* / entrada).
3.  **`fstream`**: Pode tanto ler quanto escrever.

### 1️⃣ Trabalhando com Arquivos de Texto (TXT)

#### Escrevendo em um arquivo
É exatamente igual a usar o `cout`, mas no lugar de mandar pra tela, mandamos pro arquivo!

```cpp
#include <iostream>
#include <fstream> // Biblioteca obrigatoria!

using namespace std;

int main() {
    // 1. Cria o objeto e abre (ou cria) o arquivo
    ofstream arquivoSaida("meu_diario.txt");

    // 2. Verifica se abriu direitinho
    if (arquivoSaida.is_open()) {
        // 3. Escreve no arquivo como se fosse o cout
        arquivoSaida << "Olá, Arquivo!" << endl;
        arquivoSaida << "Hoje eu aprendi C++ com meu professor." << endl;
        arquivoSaida << "Nota da aula: " << 10 << endl;
        
        // 4. Sempre feche a porta ao sair!
        arquivoSaida.close();
        cout << "Arquivo gravado com sucesso! ✅\n";
    } else {
        cout << "Erro ao abrir o arquivo! ❌\n";
    }
    return 0;
}
```

#### Lendo de um arquivo
É como usar o `cin`, mas pegando os dados do txt.

```cpp
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream arquivoEntrada("meu_diario.txt");
    string linha;

    if (arquivoEntrada.is_open()) {
        // Enquanto houver linhas para ler (getline), ele continua lendo
        while (getline(arquivoEntrada, linha)) {
            cout << "Lido: " << linha << endl; // Imprime na tela o que leu
        }
        arquivoEntrada.close();
    } else {
        cout << "Arquivo não encontrado! ❌\n";
    }
    return 0;
}
```

---

### 2️⃣ Trabalhando com Arquivos Binários (.bin ou .dat)

Aqui a coisa fica mais profissional. Vamos salvar um "bloco de memória" (uma `struct`) diretamente no disco. Usamos as funções `.write()` para salvar e `.read()` para ler. 

*Dica do Professor:* O comando `reinterpret_cast<char*>` parece assustador, mas é só um "óculos" que diz para o C++: *"Ei, olhe para essa minha variável e a trate apenas como uma sequência de bytes (chars) para eu poder salvar no disco"*.

#### Escrevendo um Binário

```cpp
#include <iostream>
#include <fstream>

using namespace std;

// Nossa estrutura de dados
struct Jogador {
    int id;
    double pontuacao;
};

int main() {
    Jogador player1 = {42, 999.5};

    // A flag ios::binary é crucial aqui!
    ofstream arqBinario("savegame.bin", ios::binary);

    if (arqBinario.is_open()) {
        // Gravamos a struct inteira de uma vez só!
        arqBinario.write(reinterpret_cast<char*>(&player1), sizeof(Jogador));
        arqBinario.close();
        cout << "Jogo salvo com sucesso (Binário)! 💾\n";
    }
    return 0;
}
```

#### Lendo um Binário

```cpp
#include <iostream>
#include <fstream>

using namespace std;

struct Jogador {
    int id;
    double pontuacao;
};

int main() {
    Jogador playerLido;

    ifstream arqBinario("savegame.bin", ios::binary);

    if (arqBinario.is_open()) {
        // Lemos os bytes do arquivo e jogamos direto na nossa struct
        arqBinario.read(reinterpret_cast<char*>(&playerLido), sizeof(Jogador));
        arqBinario.close();
        
        cout << "--- Jogo Carregado ---" << endl;
        cout << "ID: " << playerLido.id << endl;
        cout << "Pontuação: " << playerLido.pontuacao << endl;
    } else {
         cout << "Save não encontrado!\n";
    }
    return 0;
}
```

---

## 🧠 Exercícios de Fixação

Vamos ver se os conceitos grudaram na mente! 

1.  **Múltipla Escolha:** Qual é a biblioteca padrão do C++ responsável por lidar com a leitura e escrita de arquivos?
    a) `<iostream>`
    b) `<fstream>`
    c) `<string>`
    d) `<vector>`
2.  **Verdadeiro ou Falso:** A classe `ifstream` é utilizada quando queremos criar um arquivo novo e gravar dados nele. (Justifique sua resposta).
3.  **Desafio Teórico:** Por que salvar um array de 1.000 números inteiros em formato binário geralmente ocupa menos espaço no disco rígido do que salvar os mesmos 1.000 números em um arquivo texto separado por espaços?
4.  **Prática Rápida:** Escreva um programa em C++ que pede para o usuário digitar o nome dele e a idade, e salve essas informações em um arquivo chamado `perfil.txt`.

---

## 🏆 Desafios no Estilo de "Maratona de Programação"

Chegou a hora de separar os padawans dos mestres Jedi. Nos sites de juízes online (como URI/Beecrowd, Codeforces), as entradas sempre vêm de arquivos e as saídas vão para arquivos (o sistema faz isso redirecionando os fluxos padrão). 

Mas aqui, vamos simular que *você* precisa processar os arquivos do sistema.

### ⚔️ Desafio 1: O Enigma das Senhas (Arquivo Texto)
A NASA interceptou um arquivo chamado `senhas_interceptadas.txt`. Cada linha do arquivo contém uma string. Uma senha é considerada "VÁLIDA" se ela possuir mais de 8 caracteres **E** começar com a letra 'X' e ter pelo menos dois símbolos válidos dessa string -> **&%$#@+=**. 
**Sua Missão:** Crie um programa em C++ que leia o arquivo inteiro, conte quantas senhas válidas existem e escreva esse número em um arquivo de saída chamado `relatorio_nasa.txt`.
*(Dica: Crie o txt de entrada manualmente no seu computador com umas 5 palavras para testar).*

### 🛸 Desafio 2: O Banco de Dados Intergaláctico (Arquivo Binário)
Os registros dos alienígenas que visitam a Terra estão muito lentos para carregar. A Polícia Intergaláctica quer migrar tudo para binário!
**Sua Missão:** 1. Crie uma `struct Alien` contendo `int registro` e `int nivel_periculosidade`.
2. Crie um programa que cadastre 3 aliens em um vetor (array) e escreva esse vetor inteiro em um arquivo **binário** chamado `aliens.dat` usando o método `.write()`.
3. Em seguida, o programa deve limpar o vetor, abrir o arquivo `aliens.dat` usando `.read()`, carregar os dados de volta para o vetor e exibir os níveis de periculosidade na tela.

---

