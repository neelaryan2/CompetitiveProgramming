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
    int n, m;
    cin >> n >> m;
    set<int> a;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        a.insert(e);
    }
    int ans = -1;
    for (int i = 0; i < m; i++) {
        int e;
        cin >> e;
        if (a.find(e) != a.end())
            ans = e;
    }
    if (ans == -1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << "1 " << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
