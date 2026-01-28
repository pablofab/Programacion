#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, t;
    cin >> n >> t;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int maxLibros = 0;  // numero maximo de libros que dimitri puede leer
    int tActual = 0;
    int inicio = 0;  

    for (int i = 0; i < n; i++) {

        tActual += a[i];

        while (tActual > t) {   // ajustar indice de inicio hasta que el tiempo acumulado sea menor o igual a t
            tActual -= a[inicio];
            inicio++;
        }

        maxLibros = max(maxLibros, i - inicio + 1);

    }

    cout << maxLibros << endl;

    return 0;

}