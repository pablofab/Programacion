#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        string a, b;
        cin >> a >> b;

        vector<vector<int>> frec_a(26, vector<int>(n + 1, 0));
        vector<vector<int>> frec_b(26, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; ++i) {          // caluclar las frecuencias acumuladas para las cadenas a y b
            for (int j = 0; j < 26; ++j) {
                frec_a[j][i] = frec_a[j][i - 1];
                frec_b[j][i] = frec_b[j][i - 1];
            }
            frec_a[a[i - 1] - 'a'][i]++;
            frec_b[b[i - 1] - 'a'][i]++;
        }

        while (q--) {
            int l, r;
            cin >> l >> r;

            int minOp = 0;

            for (int i = 0; i < 26; ++i) {
                int count_a = frec_a[i][r] - frec_a[i][l - 1];
                int count_b = frec_b[i][r] - frec_b[i][l - 1];
                minOp += abs(count_a - count_b);
            }

            cout << minOp / 2 << endl;
        }
    }

    return 0;
}