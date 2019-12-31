#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maximumSum function below.
typedef long long ll;
#define eb emplace_back
#define rep(i, n) for(int (i) = 0; (i) < n; i++)
#define forn(i, a, b) for(int (i) = (a); (i) <= (b); i++)
#define fi first
#define se second
ll maximumSum(vector<ll> a, ll m) {
    int n = a.size();
    vector<pair<ll, ll>> pref; pref.eb(0, 0);
    rep(i, n) a[i] %= m;
    rep(i, n) pref.eb((a[i] + pref[i].fi) % m, i + 1);
    sort(pref.begin(), pref.end());
    ll ans = pref[n].fi;
    rep(i, n) {
        if (pref[i].se > pref[i + 1].se)
            ans = max(ans, (pref[i].fi - pref[i + 1].fi + m) % m);
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int q;
    cin >> q;

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n; cin >> n;
        ll m; cin >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ll result = maximumSum(a, m);
        cout << result << "\n";
    }
    return 0;
}
