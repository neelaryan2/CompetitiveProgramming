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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int mx = -1;
    for (int& e : a) {
        cin >> e;
        mx = max(mx, e);
    }
    vector<int> cnt(mx + 1, 0);
    int ptr = 0, diff = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[a[i]]++ == 0) diff++;
        while (ptr <= i && diff > k)
            if (--cnt[a[ptr++]] == 0) diff--;
        ans += i - ptr + 1;
    }
    cout << ans;
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
        cout << '\n';
    }
}
