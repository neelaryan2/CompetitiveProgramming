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
const string st = "BSC";
const int k = st.size();

void solve(int test) {
    string s;
    cin >> s;
    vector<int> cnt(k, 0), n(k), p(k);
    for (char ch : s) {
        for (int i = 0; i < k; i++)
            if (st[i] == ch) {
                cnt[i]++;
                break;
            }
    }
    for (int& e : n) cin >> e;
    for (int& e : p) cin >> e;

    ll up;
    cin >> up;
    auto check = [&](ll x) {
        ll price = 0;
        for (int i = 0; i < k; i++) {
            ll need = cnt[i] * x - n[i];
            price += max(0LL, need * p[i]);
        }
        return price <= up;
    };

    ll l = 0, r = 1e13, mid;
    while (l < r - 1) {
        mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';
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
