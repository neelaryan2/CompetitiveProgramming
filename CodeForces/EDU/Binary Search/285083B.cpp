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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& e : a)
        cin >> e;

    auto check = [&](ll x) {
        ll sum = 0, seg = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > x) return false;
            sum += a[i];
            if (sum > x) {
                sum = a[i];
                seg++;
            }
        }
        return seg + 1 <= k;
    };

    ll l = 0, r = 1e15, mid;
    while (l < r - 1) {
        mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << '\n';
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
