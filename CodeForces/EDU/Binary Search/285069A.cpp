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
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int& e : a) cin >> e;

    int ansl = -1, ansr = -1;

    auto check = [&](ld x) {
        vector<ld> p(n + 1, 0);
        vector<int> mn(n + 1, 0);
        for (int i = 0; i < n; i++) {
            p[i + 1] = a[i] - x + p[i];
            mn[i + 1] = i + 1;
            if (p[i + 1] > p[mn[i]])
                mn[i + 1] = mn[i];
        }
        for (int r = d; r <= n; r++) {
            if (p[mn[r - d]] <= p[r]) {
                ansl = mn[r - d] + 1;
                ansr = r;
                return true;
            }
        }
        ansl = -1, ansr = -1;
        return false;
    };

    ld l = 0, r = 100, mid;
    for (int i = 0; i < 100; i++) {
        mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    check(l);
    cout << ansl << ' ' << ansr << '\n';
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
    }
}
