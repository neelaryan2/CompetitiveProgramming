/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
vector<pii> a;
ll dist(pii u, pii v) {
    u.fi -= v.fi, u.se -= v.se;
    ll cur = 1LL * u.fi * u.fi + 1LL * u.se * u.se;
    return cur;
}
ll rec(int l, int r) {
    ll mn = LLONG_MAX;
    if (r - l <= 3) {
        for (int i = l; i < r; ++i)
            for (int j = i + 1; j < r; ++j)
                mn = min(mn, dist(a[i], a[j]));
        for (int i = l; i < r; ++i)
            swap(a[i].fi, a[i].se);
        sort(a.begin() + l, a.begin() + r);
        return mn;
    }
    int m = (l + r) / 2, tsz = 0;
    int midx = a[m].fi;
    mn = min(rec(l, m), rec(m, r));
    vector<pii> t(r - l);
    auto it = a.begin();
    merge(it + l, it + m, it + m, it + r, t.begin());
    copy(t.begin(), t.end(), a.begin() + l);
    int rt = sqrtl(mn) + 1;
    for (int i = l; i < r; ++i) {
        if (abs(a[i].se - midx) >= rt) continue;
        for (int j = tsz - 1; j >= 0 && a[i].fi - t[j].fi < rt; --j)
            mn = min(mn, dist(a[i], t[j]));
        t[tsz++] = a[i];
    }
    return mn;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    a.resize(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        sum += e;
        a[i] = mp(i + 1, sum);
    }
    cout << rec(0, n) << '\n';
}
