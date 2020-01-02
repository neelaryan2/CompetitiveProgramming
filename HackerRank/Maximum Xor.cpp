#include<bits/stdc++.h>
using namespace std;

#define eb emplace_back

const int max_len = 1e5 + 5, max_alpha = 2, bits = 32;
vector<vector<int>> trie(1, vector<int>(max_alpha, 0));
int root = 0;
void addTrie(int num) {
    int v = root, ind = bits - 1;
    vector<bool> s(bits, 0);
    while (num) s[ind] = num & 1, num >>= 1, ind--;
    for (int i = 0; i < bits; i++) {
        int c = s[i];
        if (trie[v][c] == 0) {
            trie.emplace_back(vector<int>(max_alpha, 0));
            trie[v][c] = trie.size() - 1;
        }
        v = trie[v][c];
    }
}
int query(int q) {
    int v = root, ind = bits - 1;
    vector<bool> s(bits, 0), ans;
    while (q) s[ind] = q & 1, q >>= 1, ind--;
    int num = 0;
    for (ind = 0; ind < bits; ind++) {
        bool b = s[ind];
        if (trie[v][!b]) ans.eb(1), v = trie[v][!b];
        else if (trie[v][b]) ans.eb(0), v = trie[v][b];
        else break;
    }
    for (ind = 0; ind < ans.size(); ind++)
        num = 2 * num + ans[ind];
    return num;
}
int main() {
    int n, a; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a, addTrie(a);
    int m, q; cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> q;
        cout << query(q) << endl;
    }
}