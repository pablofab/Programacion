#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> construirArregloPrefijos(const string &patron) {  // funcion para construir el arreglo de prefijos para KMP

    vector<int> prefijos(patron.size(), 0);

    int j = 0;
    for (int i = 1; i < (int) patron.size(); i++) {
        while (j > 0 && patron[i] != patron[j]) {
            j = prefijos[j - 1];
        }

        if (patron[i] == patron[j]) {
            j++;
        }

        prefijos[i] = j;

    }

    return prefijos;

}

int contarOcurrencias(const string &cadena, const string &patron) { // contar el num de ocurrencias del patron en la cadna

    if (patron.size() > cadena.size()) return 0;

    int ocurrencias = 0;
    
    vector<int> prefijos = construirArregloPrefijos(patron);    // array de prefijos para el patron
    
    int j = 0;
    for (int i = 0; i < (int) cadena.size(); i++) {
        while (j > 0 && cadena[i] != patron[j]) {
            j = prefijos[j - 1];
        }
        if (cadena[i] == patron[j]) {
            j++;
        }
        if (j == (int) patron.size()) {  // se encontro una coincidencia
            ocurrencias++;
            j = prefijos[j - 1];
        }
    }

    return ocurrencias;

}

int main() {

    string cadena, patron;
    cin >> cadena >> patron;
    cout << contarOcurrencias(cadena, patron) << endl;
    return 0;

}