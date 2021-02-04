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

const ll inf = 1e18;

void solve(int test, int tot) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<ll> pref(n + 2, 0);
    for (int i = 1; i <= n; i++)
        if (a[i] >= pref[i - 1])
            pref[i] = a[i] - pref[i - 1];
        else
            pref[i] = inf;

    vector<ll> suf(n + 2, 0);
    for (int i = n; i > 0; i--)
        if (a[i] >= suf[i + 1])
            suf[i] = a[i] - suf[i + 1];
        else
            suf[i] = inf;

    for (int i = 1; i < n; i++) {
        if (a[i] >= suf[i + 2] && a[i + 1] - pref[i - 1] == a[i] - suf[i + 2]) {
            cout << "YES";
            return;
        }
        if (a[i] >= pref[i - 1] && a[i] - pref[i - 1] == a[i + 1] - suf[i + 2]) {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i, t);
        cout << '\n';
    }
}
