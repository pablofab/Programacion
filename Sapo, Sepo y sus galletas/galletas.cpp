#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool verificaEtiqueta(const vector<int>& etiqueta, const string& s) {
    if (s.size() != etiqueta.size()) {
        return false;
    }

    unordered_map<char, int> letra_a_numero;
    unordered_map<int, char> numero_a_letra;

    for (int i = 0; i < (int) s.size(); ++i) {
        char letra = s[i];
        int numero = etiqueta[i];

        // verifica que la letra corresponde al numero correcto
        if (letra_a_numero.count(letra)) {
            if (letra_a_numero[letra] != numero) {
                return false;
            }
        } else {
            letra_a_numero[letra] = numero;
        }

        // vrifica que el numero corresponde a la letra correcta
        if (numero_a_letra.count(numero)) {
            if (numero_a_letra[numero] != letra) {
                return false;
            }
        } else {
            numero_a_letra[numero] = letra;
        }
    }

    return true;
}

int main() {
    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;

        vector<int> etiqueta(n);
        for (int i = 0; i < n; ++i) {
            cin >> etiqueta[i];
        }

        int m;
        cin >> m;

        for (int i = 0; i < m; ++i) {
            string s;
            cin >> s;

            if (verificaEtiqueta(etiqueta, s)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}