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
    int n, m;
    cin >> n >> m;
    map<int, array<int, 2>> mem;
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        auto it = mem.find(c);
        if (it == mem.end()) {
            mem[c] = {0, 0};
            it = mem.find(c);
        }
        (it->se)[--r] = 1;
    }
    mem[n + 1] = {1, 1};
    for (auto iti = mem.begin();; iti++) {
        auto itj = next(iti);
        if (itj == mem.end()) break;
        auto i1 = iti->se;
        if (i1[0] && i1[1]) continue;
        int c = i1[0] ? 0 : 1;
        if ((iti->fi - itj->fi) % 2)
            c ^= 1;
        if ((itj->se)[c]) {
            cout << "NO";
            return;
        }
        (itj->se)[c] = 1;
    }
    cout << "YES";
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
