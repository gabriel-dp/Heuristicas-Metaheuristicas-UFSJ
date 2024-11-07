#include <bits/stdc++.h>

using namespace std;

#define ITERACOES 100

double distancia(pair<int, int> c1, pair<int, int> c2) {
    return sqrt(pow(c1.first - c2.first, 2) + pow(c1.second - c2.second, 2));
}

double avalia(vector<int> caminho, map<int, pair<int, int>> cidades) {  // distancia total
    double total = 0;
    for (int i = 1; i < caminho.size(); i++) {
        total += distancia(cidades[caminho[i - 1]], cidades[caminho[i]]);
    }
    total += distancia(cidades[caminho[caminho.size() - 1]], cidades[caminho[0]]);
    return total;
}

void imprime_caminho(vector<int> caminho) {
    cout << "|";
    for (int i = 0; i < caminho.size(); i++) {
        cout << caminho[i] << "|";
    }
    cout << "\n";
}

int main() {
    int n, x, y;

    string buffer;
    getline(cin, buffer);
    getline(cin, buffer);
    getline(cin, buffer);
    cin >> buffer >> buffer >> n;

    map<int, pair<int, int>> cidades;
    vector<int> caminho(n);
    getline(cin, buffer);
    getline(cin, buffer);
    getline(cin, buffer);

    for (int i = 1; i <= n; i++) {
        cin >> x >> x >> y;
        cidades[i] = make_pair(x, y);
        caminho[i - 1] = i;
    }
    getline(cin, buffer);

    int contador = 0;
    cout << fixed << setprecision(2);
    vector<int> melhor_caminho(n);
    double melhor_avaliacao = -1;

    do {
        contador++;
        double avaliacao = avalia(caminho, cidades);

        if (melhor_avaliacao == -1 || melhor_avaliacao > avaliacao) {
            melhor_avaliacao = avaliacao;
            melhor_caminho = caminho;
        }

        cout << "Distancia: " << avaliacao << " >>>";
        imprime_caminho(caminho);
    } while (contador < ITERACOES && next_permutation(caminho.begin(), caminho.end()));

    cout << "\n\nMelhor Distancia: " << melhor_avaliacao << " >>>";
    imprime_caminho(melhor_caminho);

    return 0;
}