#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const ll N_MAX = 1e6;

vector<ll> factorial(N_MAX + 1);
vector<ll> inv_factorial(N_MAX + 1);

// función para calcular a^b % mod
ll pow1(ll a, ll b) {
    ll res = 1;
    a = a % MOD;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b >> 1;
    }
    return res;
}

// función para calcular factoriales e inversos modulares
void calc_factoriales() {
    factorial[0] = 1;
    for (int i = 1; i <= N_MAX; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
    inv_factorial[N_MAX] = pow1(factorial[N_MAX], MOD - 2);
    for (int i = N_MAX - 1; i >= 0; i--) {
        inv_factorial[i] = inv_factorial[i + 1] * (i + 1) % MOD;
    }
}

// calcular el coeficiente binomial
ll coef_bin(int a, int b) {
    if (b > a) {
        return 0;
    }    
    return factorial[a] * inv_factorial[b] % MOD * inv_factorial[a - b] % MOD;
}

int main() {
    calc_factoriales();

    int count = 0;
    
    int N, A, I, G;
    while (cin >> N >> A >> I >> G && count <= 1e4) {
        ll comb = coef_bin(N, A); // combinaciones de compañías
        ll grupo_comb = coef_bin(I, G); // combinaciones de grupos para una compañía
        ll total_grupo_comb = pow1(grupo_comb, A); // total combinaciones de grupos
        ll result = (comb * total_grupo_comb) % MOD;
        count++;
        cout << result << endl;
    } 

    return 0;
}