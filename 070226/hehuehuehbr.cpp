#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    string vogais = "";
    for (char c : s) {
        char lc = tolower(c);
        if (lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u') {
            vogais += lc;
        }
    }
    
    string rev = vogais;
    reverse(rev.begin(), rev.end());
    
    if (vogais == rev) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }
    
    return 0;
}

