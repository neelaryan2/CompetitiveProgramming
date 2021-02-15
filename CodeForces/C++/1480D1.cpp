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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vi> v(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v[--a[i]].eb(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int k = v[i].size();
        bool eq0 = false, eq1 = false;
        trace(i, ans);
        for (int j = 0; j < k; j++) {
            int cnt = 0;
            if (j > 0)
                cnt = v[i][j] - v[i][j - 1] - 1;
            if (cnt > 1) {
                eq0 = true;
                eq1 = false;
                ans++;
            } else if (cnt == 1) {
                if (eq0 || eq1) ans++;
            } else {
                if (!eq0) {
                    eq0 = true;
                    ans++;
                } else if (!eq1) {
                    eq1 = true;
                    ans++;
                }
            }
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
