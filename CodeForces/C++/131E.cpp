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
using vpi = vector<pii>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;

void solve(int test) {
    int n, m;
    cin >> n >> m;
    vector<vpi> v1(n), v2(n), v3(2 * n - 1), v4(2 * n - 1);
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        r--, c--;
        v1[r].eb(c, i);
        v2[c].eb(r, i);
        v3[r + c].eb(c, i);
        v4[r - c + n - 1].eb(r, i);
    }
    vector<int> cnt(m, 0), t(9, 0);
    auto rec = [&](vector<vpi>& vv) {
        for (auto& v : vv) {
            int k = v.size();
            if (k < 2) continue;
            sort(all(v));
            cnt[v[0].se]++, cnt[v[k - 1].se]++;
            for (int i = 1; i < k - 1; i++)
                cnt[v[i].se] += 2;
        }
    };
    rec(v1), rec(v2), rec(v3), rec(v4);
    for (int i = 0; i < m; i++)
        t[cnt[i]]++;
    for (int e : t)
        cout << e << ' ';
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
        cout << '\n';
    }
}
