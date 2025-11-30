#include <bits/stdc++.h>

using namespace std;


int main() {

    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // a distância entre dois pontos (x1,y1) e (x2,y2) é a raiz quadrada da soma dos quadrados das diferenças das coordenadas:
    //dist = sqrt((x2 - x1)^2 + (y2 - y1)^2). 
    //
    double distX = x2 - x1; // diferença entre os pontos xs - ponto final - ponto inicial
    double distY = y2 - y1; // diferença entre os pontos ys - ponto final - ponto inicial

    double distancia = hypot(distX, distY); // usando a função hypot (hipotenusa) 

    cout << fixed << setprecision(2) << distancia << endl; // 2 casas decimais de precisão

	return 0; // indica para a função main() que o programa retorna zero , nesse caso sem erros !!
}

