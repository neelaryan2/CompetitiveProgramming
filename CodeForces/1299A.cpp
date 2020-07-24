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
int f(vector<int>& a) {
    int n = a.size();
    if (n == 0) return 0;
    if (n == 1) return a[0];
    int val = (a[0] | a[1]) - a[1];
    for (int i = 2; i < n; i++)
        val = (val | a[i]) - a[i];
    return val;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    multiset<int> s;
    vector<int> cnt(32, 0), ans, a(n);
    for (int& e : a) {
        cin >> e;
        s.insert(e);
        for (int i = 31; i >= 0; i--)
            if ((e >> i) & 1) cnt[i]++;
    }
    for (int i = 31; i >= 0; i--) {
        if (cnt[i] != 1) continue;
        for (int e : s) {
            if ((e >> i) & 1) {
                ans.eb(e);
                s.erase(e);
                break;
            }
        }
    }
    while (!s.empty()) {
        ans.eb(*s.begin());
        s.erase(s.begin());
    }
    trace(f(a), f(ans));
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}
