#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    ll n, c, g;
    cin >> n >> c >> g;

    ll common_gcd = gcd(c, g);

    if (n >= g / common_gcd && n >= c / common_gcd) {  // verificamos si hay distancias tales que cumplan con el MCD
        cout << "SI" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

