#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> listaCanciones(n);
    for (int i = 0; i < n; ++i) {
        cin >> listaCanciones[i];
    }

    unordered_map<int, int> ultimaPos;  // un mapa para guardar la ultima posicion en la que aparecio cada cancion
    int largoSec = 0;  // tamaño maximo de la subsecuencia buscada
    int inicio = 0;

    for (int fin = 0; fin < n; ++fin) {

        if (ultimaPos.find(listaCanciones[fin]) != ultimaPos.end()) {
            inicio = max(inicio, ultimaPos[listaCanciones[fin]] + 1);
        }

        ultimaPos[listaCanciones[fin]] = fin;
        largoSec = max(largoSec, fin - inicio + 1);

    }

    cout << largoSec << endl;
    return 0;

}