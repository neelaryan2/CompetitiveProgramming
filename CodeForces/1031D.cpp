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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<char> g(n * n);
    vector<int> cnt(n * n, 0);
    vector<bool> vis(n * n, 0);
    vector<int> vec;
    vector<char> ans(2 * n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int v = n * i + j;
            cin >> g[v];
            if (i != 0) cnt[v] = max(cnt[v], cnt[v - n]);
            if (j != 0) cnt[v] = max(cnt[v], cnt[v - 1]);
            if (g[v] == 'a') cnt[v]++;
        }
    }
    vec.pb(0);
    vis[0] = true;
    for (int i = 0; i < 2 * n - 1; i++) {
        vector<int> nxt;
        bool found = false;
        for (int j = max(i + 1 - n, 0); j <= min(i, n - 1); j++) {
            int v = j * n + i - j;
            if (cnt[v] + k >= i + 1) {
                if (i - j < n - 1 && !vis[v + 1]) {
                    vis[v + 1] = true;
                    nxt.pb(v + 1);
                }
                if (j < n - 1 && !vis[v + n]) {
                    vis[v + n] = true;
                    nxt.pb(v + n);
                }
                found = true;
            }
        }
        if (found) {
            ans[i] = 'a';
            vec = nxt;
            continue;
        }
        char c = 'z';
        for (int v : vec) c = min(c, g[v]);
        ans[i] = c;
        for (int v : vec) {
            if (g[v] != c) continue;
            int j = v % n;
            if (i - j < n - 1 && !vis[v + n]) {
                vis[v + n] = true;
                nxt.pb(v + n);
            }
            if (j < n - 1 && !vis[v + 1]) {
                vis[v + 1] = true;
                nxt.pb(v + 1);
            }
        }
        vec = nxt;
    }
    for (char i : ans) cout << i;
    cout << endl;
}