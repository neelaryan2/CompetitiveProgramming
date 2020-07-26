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
void solve(int test) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<set<int>> si(20), ti(20), extra(20);
    for (int i = 0; i < n; i++)
        si[s[i] - 'a'].insert(i);
    for (int i = 0; i < n; i++)
        ti[t[i] - 'a'].insert(i);
    set<pii> have;
    int ans = 0;
    for (int c = 0; c < 20; c++) {
        for (int i : ti[c]) {
            auto it = have.lb(mp(i, -1));
            if (it->fi != i) continue;
            int ch = it->se;
            for (int j : extra[ch]){
                si[c].insert(j);
                have.erase(mp(j, ch));
            }
            extra[ch].clear();
        }
        for (int i : ti[c]) {
            auto it = si[c].find(i);
            if (it == si[c].end()) {
                cout << -1;
                return;
            }
            si[c].erase(it);
        }
        if (si[c].empty()) continue;
        ans++;
        for (int i : si[c]){
            have.insert(mp(i, c));
            extra[c].insert(i);
        }
        si[c].clear();
    }
    cout << ans;
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
        cout << "\n";
    }
}
