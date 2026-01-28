#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;
ll N_MAX = 1e6;

vector<ll> factorial(N_MAX + 1);
vector<ll> inv_factorial(N_MAX + 1);

// funcion para calcular a^b % mod
ll pow(ll a, ll b) {
    ll res = 1;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
    }
    return res;
}

// funcion para calcular factoriales e inversos modulares los cuales serviran para la formula de coef bin que se tiene despues, esto teniendo en cuenta que el valor de t (casos) es muy grande
void calc_factoriales() {
    factorial[0] = 1;
    for (int i = 1; i <= N_MAX; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
    inv_factorial[N_MAX] = pow(factorial[N_MAX], MOD - 2);
    for (int i = N_MAX - 1; i >= 0; i--) {
        inv_factorial[i] = inv_factorial[i + 1] * (i + 1) % MOD;
    }
}

// calcular el coef binomiual
ll coef_bin(int a, int b) {
    if (b > a) {
        return 0;
    }    
    return factorial[a] * inv_factorial[b] % MOD * inv_factorial[a - b] % MOD;
}

int main() {
    calc_factoriales();

    int t;
    cin >> t;
    vector<pair<int, int>> tests(t);

    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        tests[i] = {a, b};
    }

    for (const auto& case_pair : tests) {
        int a = case_pair.first;
        int b = case_pair.second;
        cout << coef_bin(a, b) << endl;
    }

    return 0;
}
