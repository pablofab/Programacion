#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int cambios = 0;
    for (int i = 0; i < k; ++i) {
        int cant_unos = 0, cant_doses = 0;
        for (int j = i; j < n; j += k) {
            if (a[j] == 1) {
                cant_unos++;
            }    
            else {
                cant_doses++;
            }
        }
    cambios += min(cant_unos, cant_doses);
    }

    cout << cambios << endl;

    return 0;

}