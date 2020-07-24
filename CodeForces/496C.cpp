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
    int n, m, ans = 0;
    cin >> n >> m;
    vector<string> st(n), tmp(n);
    for (int i = 0; i < n; i++)
        cin >> st[i];
    for (int c = 0; c < m; c++) {
        for (int i = 0; i < n; i++)
            tmp[i] += st[i][c];
        if (!is_sorted(all(tmp))) {
            ans++;
            for (int i = 0; i < n; i++)
                tmp[i].pop_back();
        }
    }
    cout << ans << '\n';
}
