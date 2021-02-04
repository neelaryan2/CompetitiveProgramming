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
#define bt(x, i) ((x >> i) & 1)
#define all(v) (v).begin(), (v).end()
const int N = 1e5 + 5;
const int B = 17;
struct trie {
    int mn;
    trie* bit[2];
    trie() { bit[0] = bit[1] = NULL, mn = N; }
};
trie* trees[N];
bool vis[N];
void add(int k, int num) {
    if (!trees[k]) trees[k] = new trie();
    trie* v = trees[k];
    for (int i = B - 1; i >= 0; i--) {
        v->mn = min(v->mn, num);
        int b = bt(num, i);
        if (!v->bit[b]) v->bit[b] = new trie();
        v = v->bit[b];
    }
    v->mn = min(v->mn, num);
}
void insert(int num) {
    if (vis[num]) return;
    vis[num] = true;
    for (int i = 1; i * i <= num; i++) {
        if (num % i) continue;
        add(i, num);
        if (i * i == num) break;
        add(num / i, num);
    }
}
int travel(trie* v, int up, int val) {
    if (!v || up < v->mn) return -1;
    for (int i = B - 1; i >= 0; i--) {
        int b = bt(val, i), nb = b ^ 1;
        if (v->bit[nb] && up >= v->bit[nb]->mn)
            v = v->bit[nb];
        else
            v = v->bit[b];
    }
    return v->mn;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;
    fill(vis, vis + N, false);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u;
            cin >> u;
            insert(u);
        } else {
            int x, k, s, ans;
            cin >> x >> k >> s;
            if (x % k)
                ans = -1;
            else
                ans = travel(trees[k], s - x, x);
            cout << ans << '\n';
        }
    }
}
