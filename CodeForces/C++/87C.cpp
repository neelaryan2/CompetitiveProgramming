/* Author - Neel Aryan (@neelaryan2) */
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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 3;
    cin >> n;
    vector<vector<pii>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        int sum = i;
        for (int j = i + 1;; j++) {
            sum += j;
            if (sum > n) brea k;
            adj[sum].eb(i, j);
        }
    }
    trace(adj);
    vector<int> mex(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        vector<int> vec;
        for (pii p : adj[i])
            vec.eb(mex[p.se] ^ mex[p.fi - 1]);
        sort(all(vec));
        vec.resize(unique(all(vec)) - vec.begin());
        int cur = vec.size();
        for (int j = 0; j < vec.size(); j++) {
            if (vec[j] != j) {
                cur = j;
                break;
            }
        }
        mex[i] = mex[i - 1] ^ cur;
    }
    int fin = mex[n] ^ mex[n - 1];
    if (fin == 0) {
        cout << "-1\n";
        return 0;
    }
    int ans = n;
    for (pii p : adj[n])
        if (mex[p.se] == mex[p.fi - 1])
            ans = min(ans, p.se - p.fi + 1);
    cout << ans << '\n';
}
