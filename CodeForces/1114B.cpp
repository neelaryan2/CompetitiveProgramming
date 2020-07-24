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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pii> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i + 1;
        sum += a[i].fi;
    }
    sort(all(a));
    int ex = n - m * k;
    vector<int> mark(n + 1, 0);
    for (int i = 0; i < ex; i++) {
        sum -= a[i].fi;
        mark[a[i].se] = 1;
    }
    for (int i = 0; i < n; i++)
        mark[i + 1] += mark[i];
    cout << sum << '\n';
    int prv = 0, cur = 0;
    for (int i = 1; i < k; i++) {
        while (cur - prv < m) cur++;
        while (mark[cur] - mark[prv] != cur - prv - m) cur++;
        prv = cur;
        cout << cur << ' ';
    }
    cout << '\n';
}
