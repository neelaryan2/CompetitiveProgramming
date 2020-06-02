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
#define NO              \
    {                   \
        cout << "-1\n"; \
        return;         \
    }
void solve() {
    int n, K = 0;
    cin >> n;
    string a, b;
    cin >> a >> b;
    set<int> cha[26];
    set<int> chb[26];
    for (int i = 0; i < n; i++) {
        trace(i);
        cha[a[i] - 'a'].insert(i);
        chb[b[i] - 'a'].insert(i);
    }
    set<int> s1 = {1, 2};
    set<int> s2 = {1, 2};
    trace(s1 == s2);
    vector<set<int>> ans(26);
    trace(cha[2]);
    trace(chb[2]);
    for (int c = 25; c >= 0; c--) {
        if (!chb[c].empty() && cha[c].empty()) NO;
        bool f = true;
        for (int i : chb[c]) {
            auto it = cha[c].find(i);
            if (it == cha[c].end()) f = false;
        }
        if (f) continue;
        K++;
        for (int i : chb[c]) {
            int t = a[i] - 'a';
            if (t < c) NO;
            cha[t].erase(i);
            ans[25 - c].insert(i);
        }
        if (cha[c].empty()) continue;
        int tmp = *cha[c].begin();
        ans[25 - c].insert(tmp);
    }
    cout << K << '\n';
    for (auto v : ans) {
        if (v.empty()) continue;
        cout << v.size() << ' ';
        for (int j : v) cout << j << ' ';
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
