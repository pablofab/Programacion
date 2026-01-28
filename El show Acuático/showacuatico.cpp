#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool puedeLlenarTanque(const vector<int>& a, int h, ll x) {

    ll aguaNecesaria = 0;
    
    for (int altura : a) {

        if (h > altura) {
            aguaNecesaria += (h - altura);  // sumamos el agua necesaria para llevar la columna a la altura h
        }
        
        if (aguaNecesaria > x) {
            return false;  // si ya excedimos el agua disponible, no es posible
        }

    }
    
    return aguaNecesaria <= x;
}

int calcularAlturaMaxima(const vector<int>& a, ll x) {

    int l = 1;
    int r = *max_element(a.begin(), a.end()) + x;
    int respuesta = l;

    while (l <= r) {

        int mid = l + (r - l) / 2;

        if (puedeLlenarTanque(a, mid, x)) {
            respuesta = mid;  // mid posibl solucion
            l = mid + 1;   // intentamos una altura mayor
        } else {
            r = mid - 1;  // intentamos una altura menor
        }

    }

    return respuesta;

}

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        ll x;
        cin >> n >> x;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int alturaMaxima = calcularAlturaMaxima(a, x);
        cout << alturaMaxima << endl;

    }

    return 0;

}