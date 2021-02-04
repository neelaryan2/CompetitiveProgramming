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
    int n, l, x, y;
    cin >> n >> l >> x >> y;
    vector<int> a(n);
    set<int> aa, xx, yy;
    for (int& e : a) {
        cin >> e;
        aa.insert(e);
        if (e + x <= l) xx.insert(e + x);
        if (e - x >= 0) xx.insert(e - x);
        if (e + y <= l) yy.insert(e + y);
        if (e - y >= 0) yy.insert(e - y);
    }
    int ab = -1, ba = -1, cross = -1;
    for (int i : xx) {
        auto it = aa.find(i);
        if (it != aa.end())
            ba = i;
        it = yy.find(i);
        if (it != yy.end())
            cross = i;
    }
    for (int i : yy) {
        auto it = aa.find(i);
        if (it != aa.end())
            ab = i;
    }
    if (ab != -1 && ba != -1) {
        cout << 0;
    } else if (ab != -1 || ba != -1) {
        cout << 1 << '\n';
        cout << ((ab == -1) ? y : x);
    } else {
        if (cross != -1) {
            cout << 1 << '\n';
            cout << cross;
        } else {
            cout << 2 << '\n';
            cout << x << ' ' << y;
        }
    }
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
