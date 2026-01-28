#include <iostream>
#include <vector>


using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    if (s.length() != t.length()) {  // diferentes longitudes, no pueden ser semejantes
        cout << "NO" << endl;
        return 0;
    }

    vector<int> dif; // para almacenar los indices donde los strings son distintos

    for (int i = 0; i < (int) s.length(); i++) {
        if (s[i] != t[i]) {
            dif.push_back(i);
        }    
    }

    if (dif.size() == 2 && s[dif[0]] == t[dif[1]] && s[dif[1]] == t[dif[0]]) { // exactamente dos diferencias y se pueden intercambiar los caracteres
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;

}