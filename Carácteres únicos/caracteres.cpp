#include <iostream>
#include <vector>

using namespace std;

struct SegmentTree {
    int N;
    vector<vector<int>> tree;

    SegmentTree(const string &s) {
        N = s.size();
        tree.resize(4 * N, vector<int>(26, 0));
        build(0, 0, N - 1, s);
    }

    int charToIndex(char c) {
        return c - 'a';
    }

    void build(int n, int i, int j, const string &s) {
        if (i == j) {
            tree[n][charToIndex(s[i])] = 1;
        } else {
            int mid = (i + j) / 2;
            build(2 * n + 1, i, mid, s);
            build(2 * n + 2, mid + 1, j, s);
            for (int k = 0; k < 26; ++k) {
                tree[n][k] = tree[2 * n + 1][k] + tree[2 * n + 2][k];
            }
        }
    }

    void update(int n, int i, int j, int t, char old_char, char new_char) {
        if (i == j) {
            tree[n][charToIndex(old_char)]--;  
            tree[n][charToIndex(new_char)]++;
        } else {
            int mid = (i + j) / 2;
            if (t <= mid) {
                update(2 * n + 1, i, mid, t, old_char, new_char);
            } else {
                update(2 * n + 2, mid + 1, j, t, old_char, new_char);
            }
            for (int k = 0; k < 26; ++k) {
                tree[n][k] = tree[2 * n + 1][k] + tree[2 * n + 2][k];
            }
        }
    }

    void update(int t, char old_char, char new_char) {
        update(0, 0, N - 1, t, old_char, new_char);
    }

    vector<int> query(int l, int r, int n, int i, int j) {
        if (r < i || l > j) {
            return vector<int>(26, 0);
        }
        if (l <= i && j <= r) {
            return tree[n];
        }

        int mid = (i + j) / 2;
        vector<int> left_res = query(l, r, 2 * n + 1, i, mid);
        vector<int> right_res = query(l, r, 2 * n + 2, mid + 1, j);
        vector<int> result(26, 0);
        for (int k = 0; k < 26; ++k) {
            result[k] = left_res[k] + right_res[k];
        }
        return result;
    }

    vector<int> query(int l, int r) {
        return query(l, r, 0, 0, N - 1);
    }

    int countDistinct(const vector<int>& freq) {
        int count = 0;
        for (int f : freq) {
            if (f > 0) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    string s;
    int q;
    cin >> s >> q;

    SegmentTree segTree(s);

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            segTree.update(pos - 1, s[pos - 1], c);  
            s[pos - 1] = c;
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            vector<int> freq = segTree.query(l - 1, r - 1); 
            cout << segTree.countDistinct(freq) << endl;
        }
    }

    return 0;
}