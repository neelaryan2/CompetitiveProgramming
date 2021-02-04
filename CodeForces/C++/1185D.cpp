/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
bool check(vector<pii> vec) {
    int n = vec.size();
    if (vec.size() <= 2) return true;
    int d = vec[1].fi - vec[0].fi;
    for (int i = 1; i < n; i++) {
        if (vec[i].fi - vec[i - 1].fi != d)
            return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pii> vec(n);
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        vec[i] = mp(e, i + 1);
    }
    sort(all(vec));
    if (vec.size() == 2) {
        cout << "1\n";
        return 0;
    }
    pii a = vec[n - 1];
    pii b = vec[n - 2];
    vec.pop_back();
    if (check(vec)) {
        cout << a.se << '\n';
        return 0;
    }
    vec.pop_back();
    vec.pb(a);
    if (check(vec)) {
        cout << b.se << '\n';
        return 0;
    }
    vec.pop_back();
    vec.pb(b), vec.pb(a);
    int d = b.fi - a.fi, ans = -1;
    trace(a, b);
    trace(vec);
    int p = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a.fi + 1LL * p * d != vec[i].fi) {
            if (ans != -1) {
                cout << "-1\n";
                return 0;
            }
            ans = vec[i].se;
        } else
            p++;
    }
    cout << ans << '\n';
}
