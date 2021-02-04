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

int query(vi& a, vi& b) {
    cout << a.size() << ' ' << b.size() << ' ';
    for (int e : a) cout << e << ' ';
    for (int e : b) cout << e << ' ';
    cout << endl;
    int x;
    cin >> x;
    return x;
}

void solve(int test) {
    int n;
    cin >> n;
    vi base(1, 1);
    vi a(1, 1), b(n - 1);
    for (int i = 1; i < n; i++)
        b[i - 1] = i + 1;

    int dist = query(base, b);
    
    while (b.size() > 1) {
        int sz = b.size() / 2;
        a.clear();
        while (sz--) {
            a.push_back(b.back()); 
            b.pop_back();
        }
        int d = query(base, b);
        if (d < dist)
            swap(a, b);
    }
    a.resize(n - 1);
    for (int i = 1, p = 0; i <= n; i++)
        if (i != b[0])
            a[p++] = i;

    dist = query(a, b);
    cout << "-1 " << dist << endl;
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
    }
}
