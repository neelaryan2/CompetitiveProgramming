/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
string t, p;
vector<int> a;
bool check(int k) {
    int n = t.size();
    vector<bool> vis(n, false);
    for (int i = 0; i < k; i++)
        vis[a[i]] = true;
    string cur;
    int j = 0, m = p.size();
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        if (p[j] == t[i]) j++;
        if (j == m) return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t >> p;
    int n = t.size();
    a.resize(n);
    for (int& e : a) cin >> e, e--;
    int lo = 0, hi = n, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) / 2;
        if (check(mid))
            lo = mid;
        else
            hi = mid;
    }
    cout << lo << '\n';
}
