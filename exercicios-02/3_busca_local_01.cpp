#include <bits/stdc++.h>

using namespace std;

#define ITERACOES 100

pair<int, int> avalia(vector<bool> mochila, vector<pair<int, int>> itens, int capacidade) {  // <peso, valor>
    pair<int, int> resultado = make_pair(0, 0);
    for (int i = 0; i < mochila.size(); i++) {
        if (mochila[i]) {
            resultado.first += itens[i].first;
            resultado.second += itens[i].second;
        }
    }
    return (resultado.first <= capacidade) ? resultado : make_pair(-1, -1);
}

int main() {
    int n, capacidade, peso, valor;
    int total_peso = 0, total_valor = 0;

    cin >> n >> capacidade;

    vector<pair<int, int>> itens(n);
    vector<bool> mochila(n);
    for (int i = 0; i < n; i++) {
        // Recebe o peso e valor de cada item
        cin >> peso >> valor;
        itens[i] = make_pair(peso, valor);

        // Coloca o item na mochila se ele couber
        if (total_peso + peso <= capacidade) {
            total_peso += peso;
            total_valor += valor;
            mochila[i] = true;
        } else {
            mochila[i] = false;
        }
    }

    int contador = 0;
    do {
        contador++;
        pair<int, int> avaliacao = avalia(mochila, itens, capacidade);

        if (avaliacao.first != -1) {
            cout << "Peso: " << avaliacao.first << " | Valor: " << avaliacao.second << " >>> ";
            for (int i = 0; i < mochila.size(); i++) {
                cout << (mochila[i] ? "1" : "0") << "|";
            }
            cout << "\n";
        }
    } while (contador < ITERACOES && next_permutation(mochila.begin(), mochila.end()));

    return 0;
}