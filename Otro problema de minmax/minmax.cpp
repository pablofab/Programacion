#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool esValidaParticion(const vector<int>& arr, int n, int k, ll maxSum) {

    ll sumaActual = 0;
    int subarreglos = 1;
    
    for (int i = 0; i < n; i++) {
        if (sumaActual + arr[i] > maxSum) {
            subarreglos++;   // si la suma actual excede maxSum, iniciamos un nuevo subarreglo
            sumaActual = arr[i];
            
            if (subarreglos > k) {   // si excedemos el numero de subarreglos permitidos, devolvemos falsee
                return false;
            }

        } else {
            sumaActual += arr[i];   // si la suma actual no excede, sumamos el valor al subarreglo actual
        }
    }

    return true;

}

ll particionMinMaxSuma(const vector<int>& arr, int n, int k) {

    ll l = *max_element(arr.begin(), arr.end());  // el numero mas grande del arreglo
    ll r = 0;  // la suma total
    
    for (int i = 0; i < n; i++) {
        r += arr[i];
    }
    
    ll respuesta = r;
    
    while (l <= r) {     // busqueda binaria sobre el valor de la suma maxima

        ll mid = l + (r - l) / 2;
        
        if (esValidaParticion(arr, n, k, mid)) {
            respuesta = mid;  // si es posible, intentamos con una suma maxima mas pequeña
            r = mid - 1;
        } else {
            l = mid + 1;  // si no, aumentamos la suma maxima permitida
        }
    }
    
    return respuesta;

}

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << particionMinMaxSuma(arr, n, k) << endl;
    
    return 0;

}