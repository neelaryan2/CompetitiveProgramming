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

vector<int> siz, par;
void makeset(int a) {
    par[a] = a;
    siz[a] = 1;
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
    siz[a] += siz[b];
    par[b] = a;
}

void solve(int test) {
    int n;
    cin >> n;
    par.resize(n);
    siz.resize(n);
    for (int i = 0; i < n; i++)
        makeset(i);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        int ans = root(x - 1);
        unite((ans + 1) % n, ans);
        cout << 1 + ans << ' ';
    }
    cout << '\n';
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
