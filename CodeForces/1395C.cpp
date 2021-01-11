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
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;

void solve(int test) {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int& e : a) cin >> e;

    vector<set<int>> st(n);
    for (int& e : b) {
        cin >> e;
        for (int i = 0; i < n; i++)
            st[i].insert(e);
    }
    int ans = 0;
    for (int b = 9; b >= 0; b--) {
        int fuck = false;
        for (int i = 0; i < n; i++) {
            int c = ((a[i] >> b) & 1);
            if (!c) continue;
            int f = 1;
            for (int j : st[i]) {
                int t = (j >> b) & 1;
                f &= t;
            }
            if (f) {
                fuck = true;
                break;
            }
        }
        if (fuck) {
            ans ^= (1 << b);
            continue;
        }
        for (int i = 0; i < n; i++) {
            int c = ((a[i] >> b) & 1);
            if (!c) continue;
            set<int> cur;
            for (int j : st[i]) {
                int t = (j >> b) & 1;
                if (!t) cur.insert(j);
            }
            swap(st[i], cur);
        }
    }
    cout << ans;
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
