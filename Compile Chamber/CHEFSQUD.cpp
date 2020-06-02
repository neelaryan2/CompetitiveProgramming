/* Author - Neel Aryan (@neelaryan2) */
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
int n;
vector<int> a;
map<int, int> comp;
void add(vector<ll>& B, int i, ll x) {
    int n = B.size();
    for (; i < n; i += i & (-i))
        B[i] = B[i] + x;
}
ll sum(vector<ll>& B, int i) {
    ll sum = 0;
    for (; i > 0; i -= i & (-i))
        sum = sum + B[i];
    return sum;
}
ll search(ll x) {
    vector<ll> B(n + 10, 0);
    ll ret = 0, curr = 0;
    for (int r = 0, l = 0; r < n; r++) {
        curr += sum(B, comp[a[r]]);
        add(B, comp[a[r]], a[r]);
        while (l < r && curr > x) {
            add(B, comp[a[l]], -a[l]);
            l++;
        }
        ret += r - l + 1;
    }
    return ret;
}
void solve() {
    comp.clear();
    cin >> n;
    a.resize(n);
    for (int& e : a) cin >> e, comp[e] = 0;
    int cnt = 1;
    for (auto p : comp)
        comp[p.fi] = cnt++;
    ll goal = (1LL * n * (n + 1)) / 2;
    goal = (goal + 1) / 2;
    ll lo = -1, hi = 1e18, mid;
    while (lo < hi - 1) {
        mid = lo + (hi - lo) / 2;
        if (search(mid) < goal)
            lo = mid;
        else
            hi = mid;
    }
    cout << hi << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
