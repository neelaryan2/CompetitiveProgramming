#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pii> arr(n);
    for (pii& a : arr) cin >> a.fi;
    for (pii& a : arr) cin >> a.se;
    pii mx = mp(0, 0), tmp;
    ll ans = 0;
    for (pii& p : arr) {
        tmp.fi = mx.se + p.fi;
        tmp.se = mx.fi + p.se;
        mx.fi = max(mx.fi, tmp.fi);
        mx.se = max(mx.se, tmp.se);
        ans = max({ans, tmp.fi, tmp.se});
    }
    cout << ans << endl;
}