#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7; 

// funcion para calcular a^b % mod
ll pow1(ll a, ll b, ll mod) {
    ll res = 1;
    a = a % MOD;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    vector<ll> results(t);
    for (int i = 0; i < t; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
    
        ll exp = pow1(b, c, MOD-1);  // se calcula b^c % (MOD-1) debido al teorema de Fermat
        results[i] = pow1(a, exp, MOD);
        
    }
    for (const auto& res : results) {
        cout << res << endl;
    }
    return 0;
}
