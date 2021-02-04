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

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), c(n);
    for (int& e : p) cin >> e, e--;
    for (int& e : c) cin >> e;
    vector<vi> cyc;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        int j = i;
        cyc.eb();
        while (!vis[j]) {
            vis[j] = true;
            cyc.back().eb(j);
            j = p[j];
        }
    }
    int ans = n;
    for (auto& v : cyc) {
        int k = v.size();
        vector<int> div;
        for (int i = 1; i * i <= k; i++) {
            if (k % i) continue;
            div.eb(i), div.eb(k / i);
        }
        sort(all(div));
        for (int f : div) {
            bool found = false;
            for (int i = 0; i < f; i++) {
                int col = c[v[i]];
                bool skip = false;
                for (int j = i; j < k; j += f) {
                    if (c[v[j]] != col) {
                        skip = true;
                        break;
                    }
                }
                if (!skip) {
                    found = true;
                    break;
                }
            }
            if (found) {
                ans = min(ans, f);
                break;
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
}
