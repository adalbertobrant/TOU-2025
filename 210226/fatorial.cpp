#include <bits/stdc++.h>

using namespace std;

// fatorial recursivo 

long long int fatorial(int n){

    if ( n == 1 || n == 0 ) return 1;
    return n * fatorial ( n - 1 );
}

void main(int x, double k ){ cout << x / k << endl; }

int main() {
/*
    int n;

    cout << " Entre um numero -> ";
    cin >> n;
    
    long long int res = fatorial(n);
    cout << " Fatorial "<< n << " == " << res << endl; */

// execução da função vazia ( void ) 
    int n1 = 10;
    double n2 = 100.0;
    main(n1, n2);

	return 0;
}

