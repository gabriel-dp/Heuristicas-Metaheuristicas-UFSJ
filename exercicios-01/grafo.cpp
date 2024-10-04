#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, map<int, int>> grafo;
    int n, m, origem, destino, custo;

    cin >> n >> m;

    // Vertices
    for (int i = 1; i <= n; i++) {
        grafo[i];  // Inicializa origem vazia
    }

    // Arestas
    for (int i = 0; i < m; i++) {
        cin >> origem >> destino >> custo;
        grafo[origem][destino] = custo;
        grafo[destino][origem] = custo;  // Bidirecional
    }

    // Imprime grafo
    for (auto i : grafo) {
        cout << i.first << ": ";
        for (auto j : i.second) {
            cout << j.first << "(" << j.second << ")" << " | ";
        }
        cout << "\n";
    }

    return 0;
}