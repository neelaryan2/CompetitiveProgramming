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

vector<int> siz, par, mx;
void makeset(int a) {
    par[a] = a;
    siz[a] = 1;
    mx[a] = a;
}
int root(int a) {
    int _a = a;
    while (a != par[a]) a = par[a];
    par[_a] = a;
    return a;
}
void unite(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b];
    par[b] = a;
    mx[a] = max(mx[a], mx[b]);
}

void solve(int test) {
    int n, m;
    cin >> n >> m;
    par.resize(n + 1);
    siz.resize(n + 1);
    mx.resize(n + 1);
    for (int i = 0; i <= n; i++)
        makeset(i);

    while (m--) {
        string t;
        int x;
        cin >> t >> x;
        trace(t, x);
        if (t == "-") {
            unite(x - 1, x);
        }
        if (t == "?") {
            int ans = mx[root(x - 1)];
            if (ans == n) ans = -2;
            cout << 1 + ans << '\n';
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
    }
}