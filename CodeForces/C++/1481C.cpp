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
    vector<int> a(n), b(n), c(m);
    for (int& e : a) cin >> e, e--;
    for (int& e : b) cin >> e, e--;
    for (int& e : c) cin >> e, e--;
    vector<vi> eq(n), neq(n);
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i])
            eq[a[i]].eb(i);
        else
            neq[b[i]].eb(i);
    }
    int ptr = m - 1, ref = -1;
    vector<int> ans(m);
    if (!neq[c[ptr]].empty()) {
        ref = neq[c[ptr]].back();
        neq[c[ptr]].pop_back();
        ans[ptr--] = ref;
    } else if (!eq[c[ptr]].empty()) {
        ref = eq[c[ptr]].back();
        ans[ptr--] = ref;
    } else {
        cout << "NO";
        return;
    }
    trace(ans, ref, a, b, c);
    while (ptr >= 0) {
        if (neq[c[ptr]].empty()) {
            ans[ptr--] = ref;
            continue;
        }
        ans[ptr] = neq[c[ptr]].back();
        neq[c[ptr]].pop_back();
        ptr--;
    }
    for (int i = 0; i < n; i++) {
        if (!neq[i].empty()) {
            cout << "NO";
            return;
        }
    }
    cout << "YES\n";
    for (int i : ans)
        cout << (i + 1) << ' ';
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
