#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ppi = pair<pii, int>;
using vpi = vector<pii>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define runtime() (int)(1000 * ((double)clock()) / CLOCKS_PER_SEC)
using vi = vector<int>;
int block = 590;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> w(n);
    for (int& e : w) cin >> e;
    int p;
    cin >> p;
    vector<ll> ans(p);
    vector<vector<pii>> que(n + 1);
    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        if (b > block) {
            ll cur = 0;
            for (int j = a; j < n; j += b)
                cur += w[j];
            ans[i] = cur;
        } else {
            que[b].pb({a, i});
        }
    }
    for (int b = 1; b <= n; b++) {
        if (que[b].empty()) continue;
        vector<ll> dp(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (i + b < n)
                dp[i] = dp[i + b] + w[i];
            else
                dp[i] = w[i];
        }
        for (pii& p : que[b]) {
            ans[p.se] = dp[p.fi];
        }
    }
    for (ll& i : ans) cout << i << '\n';
}