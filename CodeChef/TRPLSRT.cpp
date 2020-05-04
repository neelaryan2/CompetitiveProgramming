#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ppi = pair<pii, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n), pos(n), vec;
    vector<ppi> ans;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        pos[p[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        if (p[i] == i) continue;
        int j = pos[i], k = pos[j];
        if (j != p[i]) {
            ans.pb({{k + 1, j + 1}, i + 1});
            p[k] = p[i];
            pos[p[i]] = k;
            pos[j] = j;
            pos[i] = i;
            p[j] = j;
            p[i] = i;

        } else {
            if (vis[i]) continue;
            vis[i] = true;
            vis[p[i]] = true;
            vec.pb(i);
        }
    }
    int sz = vec.size();
    if (sz % 2 || ans.size() + sz > k) {
        cout << -1 << '\n';
        return;
    }
    for (int t = 0; t < sz; t += 2) {
        int i = vec[t], j = vec[t + 1];
        ans.pb({{p[i] + 1, i + 1}, j + 1});
        ans.pb({{p[j] + 1, j + 1}, p[i] + 1});
    }
    cout << ans.size() << '\n';
    for (ppi p : ans)
        cout << p.fi.fi << ' ' << p.fi.se << ' ' << p.se << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
