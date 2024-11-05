#include <bits/stdc++.h>

using namespace std;

map<int, map<int, int>> grafo;
int n, m;

int contador = 0;
set<int> numeros;

int calcula_distancia(string caminho) {
    int total = 0;
    for (int i = 0; i < caminho.size() - 1; i++) {
        total += grafo[caminho[i] - '0'][caminho[i + 1] - '0'];
    }
    return total;
}

void imprime_recursivo(string str, int atual) {
    if (numeros.size() == 0) {
        contador++;
        cout << str << " | " << contador << " | " << calcula_distancia(str) << "\n";
        return;
    }

    for (int numero : numeros) {
        if (atual != numero && grafo[atual].find(numero) == grafo[atual].end()) return;

        str += to_string(numero);
        numeros.erase(numero);
        imprime_recursivo(str, numero);
        numeros.insert(numero);
        str.pop_back();
    }
}

int main() {
    int origem, destino, custo;

    cin >> n >> m;

    // Vertices
    for (int i = 1; i <= n; i++) {
        grafo[i];  // Inicializa origem vazia
        numeros.insert(i);
    }

    // Arestas
    for (int i = 0; i < m; i++) {
        cin >> origem >> destino >> custo;
        grafo[origem][destino] = custo;
        grafo[destino][origem] = custo;  // Bidirecional
    }

    // Imprime as permutacoes
    imprime_recursivo("", 1);

    return 0;
}