/* Author - Neel Aryan (@neelaryan2) */
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
const int d = 3;
vector<pii> ans;
vector<vi> p;
int solve(vector<int> ind, int c) {
    if (c == d) return ind[0];
    map<int, vector<int>> cur;
    for (int i : ind)
        cur[p[i][c]].pb(i);
    vector<int> vec;
    for (auto t : cur) {
        int left = solve(t.se, c + 1);
        if (left != -1) vec.pb(left);
    }
    int k = vec.size();
    for (int i = 1; i < k; i += 2)
        ans.eb(vec[i] + 1, vec[i - 1] + 1);
    return (k & 1) ? vec.back() : -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    p.assign(n, vi(d, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < d; j++)
            cin >> p[i][j];
    vector<int> ind(n);
    iota(all(ind), 0);
    solve(ind, 0);
    for (pii p : ans) 
        cout << p.fi << ' ' << p.se << '\n';
}
