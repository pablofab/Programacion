#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool puedeProducir(const vector<int>& tiempos, ll x, ll k) {

    ll figurasProducidas = 0;

    for (int t : tiempos) {
        figurasProducidas += x / t;  // cuantas figuras puede producir esta impresora en x segundos?
        if (figurasProducidas >= k) {
            return true;     // si ya alcanzamos k figuras, terminamos la busqueda
        }
    }

    return figurasProducidas >= k;

}

ll tiempoMinimoParaKFiguras(const vector<int>& tiempos, ll k) {

    ll l = 0;
    ll tiempoMinimo = tiempos[0];

    for (int t : tiempos) {
        if (t < tiempoMinimo) {
            tiempoMinimo = t;
        }
    }

    ll r = tiempoMinimo * k;
    ll respuesta = r;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (puedeProducir(tiempos, mid, k)) {
            respuesta = mid;  // si es posible producir k figuras en mid segundos, intentamos menos tiempo
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return respuesta;

}

int main() {

    int n;
    ll k;
    cin >> n >> k;
    vector<int> tiempos(n);

    for (int i = 0; i < n; i++) {
        cin >> tiempos[i];
    }

    cout << tiempoMinimoParaKFiguras(tiempos, k) << endl;
    return 0;

}