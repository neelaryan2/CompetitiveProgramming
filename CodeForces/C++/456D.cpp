#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const int K = 26;
struct trie {
    bool leaf, win, lose;
    trie* nxt[K];
    trie() {
        leaf = true, win = false, lose = false;
        for (int i = 0; i < K; i++) nxt[i] = NULL;
    }
};
void add(trie* root, string const& s) {
    trie* v = root;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if (!v->nxt[c]) {
            v->nxt[c] = new trie();
            v->leaf = false;
        }
        v = v->nxt[c];
    }
}
void dfs(trie* v) {
    if (v->leaf) {
        v->lose = true;
        return;
    }
    for (int i = 0; i < K; i++) {
        trie* to = v->nxt[i];
        if (!to) continue;
        dfs(to);
        v->win = v->win || !to->win;
        v->lose = v->lose || !to->lose;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    trie* root = new trie();
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        add(root, s);
    }
    dfs(root);
    if (!root->win)
        cout << "Second\n";
    else {
        if (root->lose)
            cout << "First\n";
        else {
            if (k & 1)
                cout << "First\n";
            else
                cout << "Second\n";
        }
    }
}