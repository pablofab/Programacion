#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string input;
        cin >> input;

        priority_queue<int> minus;   // Priority queues para registrar la posicion de los caracteres
        priority_queue<int> mayus;

        vector<char> result;

        for (int i = 0; i < (int) input.size(); ++i) {
            char ch = input[i];
            if (ch == 'b') {
                // eliminar la minuscula de mas a la derecha
                while (!minus.empty()) {
                    int pos = minus.top();
                    if (pos >= (int) result.size()) {
                        minus.pop();
                    } else {
                        result[pos] = '\0';  // posicion donde se debe eliminar
                        minus.pop();
                        break;
                    }
                }
            } else if (ch == 'B') {
                // eliminar la mayuscula de mas a la derecha
                while (!mayus.empty()) {
                    int pos = mayus.top();
                    if (pos >= (int) result.size()) {
                        mayus.pop();
                    } else {
                        result[pos] = '\0';  // posicion donde se debe eliminar
                        mayus.pop();
                        break;
                    }
                }
            } else {
                result.push_back(ch);
                if (islower(ch)) {
                    minus.push(result.size() - 1);
                } else if (isupper(ch)) {
                    mayus.push(result.size() - 1);
                }
            }
        }

        string resultStr;
        for (char ch : result) {
            if (ch != '\0') {
                resultStr += ch;
            }
        }

        cout << resultStr << endl;
    }

    return 0;
}