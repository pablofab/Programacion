#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_map<int, pair<int, int>> map;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            map[a[i] + a[j]] = {i, j};
        }    
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = a[i] + a[j];
            if (map.find(x - sum) != map.end()) {
                pair<int, int> p = map[x - sum];
                if (p.first != i && p.first != j && p.second != i && p.second != j) {
                    cout << i + 1 << " " << j + 1 << " " << p.first + 1 << " " << p.second + 1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
    
}