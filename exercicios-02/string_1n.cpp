#include <bits/stdc++.h>

using namespace std;

int contador = 0;
set<int> numeros;

void imprime_recursivo(string str) {
    if (numeros.size() == 0) {
        contador++;
        cout << str << " | " << contador << "\n";
        return;
    }

    for (int numero : numeros) {
        str += to_string(numero);
        numeros.erase(numero);
        imprime_recursivo(str);
        numeros.insert(numero);
        str.pop_back();
    }
}

int main() {
    int n;

    cout << "Tamanho da string: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        numeros.insert(i);
    }

    imprime_recursivo("");

    return 0;
}