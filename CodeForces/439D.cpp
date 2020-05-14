#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    sort(all(a));
    sort(all(b));
    vector<ll> pa(n + 1, 0), pb(m + 1, 0);
    for (int i = 0; i < n; i++)
        pa[i + 1] = pa[i] + a[i];
    for (int i = 0; i < m; i++)
        pb[i + 1] = pb[i] + b[i];
    ll ans = 1e18;
    for (int i = 0; i < m; i++) {
        int j = lower_bound(all(a), b[i]) - a.begin();
        ll lef = (pb[m] - pb[i]) - 1LL * (m - i) * b[i];
        ll righ = 1LL * j * b[i] - pa[j];
        ans = min(ans, lef + righ);
    }
    for (int i = 0; i < n; i++) {
        int j = upper_bound(all(b), a[i]) - b.begin();
        ll lef = (pb[m] - pb[j]) - 1LL * (m - j) * a[i];
        ll righ = 1LL * i * a[i] - pa[i];
        ans = min(ans, lef + righ);
    }
    cout << ans << endl;
}
