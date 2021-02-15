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
    ll A, B, n;
    cin >> A >> B >> n;
    vector<int> a(n), b(n);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    for (int i = 0; i < n; i++)
        B -= 1LL * (1 + (b[i] - 1) / A) * a[i];

    for (int i = 0; i < n; i++) {
        B += a[i];
        if (B > 0) {
            cout << "YES";
            return;
        }
        B -= a[i];
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
        solve(i);
        cout << '\n';
    }
}
