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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    map<int, int> cnt;
    ll ans = 0;
    for (int& e : a) {
        cin >> e;
        auto it = cnt.find(e ^ x);
        if (it != cnt.end())
            ans += it->se;
        cnt[e]++;
    }
    cout << ans << '\n';
}
