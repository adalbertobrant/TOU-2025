# include <bits/stdc++.h>

using namespace std;

int main(){

// declaração de dois vetores dinamicamente
  vector<int> x;
  vector<int> y;

  int tam_x;
  int tam_y;

// insere na posição final do vetor
  x.push_back(100);
  x.push_back(90);
  x.push_back(80);
  x.push_back(55);
  x.push_back(42);

  y.push_back(1);
  y.push_back(2);
  y.push_back(3);
  y.push_back(4);
  y.push_back(5);

// tamanho do vector x e y
  tam_x = x.size();
  tam_y = y.size();

  cout << "Tamanho do vector x " << tam_x << endl;
  cout << "Tamanho do vector y " << tam_y << endl;

// imprime elementos na tela do vector x
  cout << " Vetor X " << endl;
  for ( int i = 0; i < tam_x; i++ ){
    cout << x[i] << " ";
  }
  cout << endl;
// imprime elementos na tela do vector y
  cout << " Vetor Y " << endl;
  for ( int i = 0; i < tam_y; i++ ){
    cout << y[i] << " ";
  }
  cout << endl;

// troca de valores entre dois vectors swap - vetor a ser trocado com vetor a ocorrer a troca
  x.swap(y);
  cout << endl;
  cout << "Vetor X tem os mesmos valores de vetor Y" << endl;
  for ( int i = 0; i < tam_x; i++ ){
    cout << x[i] << " ";
  }
// troca novamente o y pelo x
  y.swap(x);
  cout << endl;

// front() , back(), at()
  cout << "Primeiro elemento do vetor x "<< x.front() << endl;
  cout << "Último elemento do vetor x " << x.back() << endl;
  cout << "Elemento do meio do vetor x " << x.at(tam_x/2) << endl;

// inserir elementos no vetor y
  cout << "Insere 33 no início do vetor y" << endl;

  y.insert(y.begin(),33); // insere o 33 no início do vetor y
  for ( int i = 0; i < y.size(); i++ ){
    cout << y[i] << " ";
  }
  cout << endl;
// insere elemento no vetor y na última posição
  cout << "Insere 77 no fim do vetor y" << endl;

  y.insert(y.end(),77); // insere o 77 no fim do vetor y
  for ( int i = 0; i < y.size(); i++ ){
    cout << y[i] << " ";
}
  cout << endl;
// remover elementos do vetor x
  x.erase(x.end() - 1);
  cout << "Remove elemento no fim do vetor x" << endl;
  for ( int i = 0; i < x.size(); i++ ){
    cout << x[i] << " ";
  }
  cout << endl;
// verifica se o vetor y está vazio

  while ( !y.empty() ){
    y.pop_back(); // remove o elemento
  }
  cout << "Novo tamanho do vetor y " << y.size() << endl;

// limpa o vetor por completo
  x.clear();
  cout << "Novo tamanho do vetor x " << x.size() << endl;
  return 0;
}
