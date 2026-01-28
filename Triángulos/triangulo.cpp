#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long result;
    if (n % 3 == 0) {
        result = ((n - 1) / 2) * n - (2 * n / 3);
    } else {
        result = ((n - 1) / 2) * n;
    }

    cout << result << endl;
    return 0;
}