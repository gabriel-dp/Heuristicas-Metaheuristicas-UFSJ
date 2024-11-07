#include <bits/stdc++.h>

using namespace std;

int contador = 0;

void imprime_recursivo(string str, int index) {
    if (index >= str.size()) {
        contador++;
        cout << str << " | " << contador << "\n";
        return;
    }

    imprime_recursivo(str, index + 1);

    str[index] = '1';
    imprime_recursivo(str, index + 1);
}

int main() {
    int n;

    cout << "Tamanho da string: ";
    cin >> n;

    string str = "";
    for (int i = 0; i < n; i++) {
        str += to_string(0);
    }

    imprime_recursivo(str, 0);

    return 0;
}