#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
void solve(int test) {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<int> b(n);
    for (ll& e : a) cin >> e;
    vector<set<int>> parents(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] != -1)
            parents[--b[i]].insert(i);
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (parents[i].size() == 0)
            q.push(i);
    vector<int> ans(n);
    int l = 0, r = n - 1;
    vector<ll> tmp = a;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (tmp[v] >= 0) ans[l++] = v;
        if (tmp[v] < 0) ans[r--] = v;
        int u = b[v];
        if (u == -1) continue;
        if (tmp[v] > 0) tmp[b[v]] += tmp[v];
        parents[u].erase(v);
        if (parents[u].size() == 0)
            q.push(u);
    }
    ll sum = 0;
    for (int i : ans) {
        sum += a[i];
        if (b[i] != -1)
            a[b[i]] += a[i];
    }
    cout << sum << '\n';
    for (int i : ans) cout << i + 1 << ' ';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << "\n";
    }
}
