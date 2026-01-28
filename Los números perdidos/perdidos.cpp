#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> mi_vector(n);
    vector<bool> mi_vector2(n + 1, false);

    for (int i = 0; i < n; i++) {
        cin >> mi_vector[i];
        if (mi_vector[i] <= n) {
            mi_vector2[mi_vector[i]] = true;
        }
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!mi_vector2[i]) {
         count++;
        }
    }

    cout << count << endl;

    return 0;
}