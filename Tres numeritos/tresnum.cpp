#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        int impares[3], pares[2];  // Para almacenar los índices de los primeros 3 impares y 2 pares
        int countImpares = 0, countPares = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) {
                if (countPares < 2) {  // Solo necesitamos los primeros 2 pares
                    pares[countPares++] = i + 1;
                }
            } else {
                if (countImpares < 3) {  // Solo necesitamos los primeros 3 impares
                    impares[countImpares++] = i + 1;
                }
            }
        }

        if (countImpares >= 3) {    // al menos tres impares (seleccionamos los primeros tres)
            cout << "YES" << endl;
            cout << impares[0] << " " << impares[1] << " " << impares[2] << endl;
        } else if (countImpares >= 1 && countPares >= 2) {  // al menos un impar y al mnos dos pares (tal suma s impar)
            cout << "YES" << endl;
            cout << impares[0] << " " << pares[0] << " " << pares[1] << endl;
        } else {   // no es posible formar una suma impar con tres números
            cout << "NO" << endl;
        }
    }

    return 0;

}

