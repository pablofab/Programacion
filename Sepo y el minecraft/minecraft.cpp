#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool esValido(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

int aguaMinima(int n, int m) {
    vector< vector<int> > mat( n , vector<int>(m, 0) );
    int cantAgua = 0;

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            bool arriba = esValido(i-1, j, n, m) && mat[i-1][j]==1;
            bool abajo = esValido(i+1, j, n, m) && mat[i+1][j]==1;
            bool izquierda = esValido(i, j-1, n, m) && mat[i][j-1]==1;
            bool derecha = esValido(i, j+1, n, m) && mat[i][j+1]==1;

            if ((arriba || abajo) && (izquierda || derecha)){
                mat[i][j]=1;
            }
            else{
                mat[i][j]=1;
                cantAgua++;
            }
        }
    }

    return cantAgua - min(n-1, m-1);
}

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;

        cout << aguaMinima(n, m) << endl;
    }

    return 0;
}