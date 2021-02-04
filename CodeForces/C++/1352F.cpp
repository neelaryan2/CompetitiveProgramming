#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

void solve() {
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;
    vector<int> ans;
    if (n0) {
        for (int i = 0; i <= n0; i++)
            ans.pb(0);
    }
    if (n2) {
        for (int i = 0; i <= n2; i++)
            ans.pb(1);
    }
    if (n2 && n0 && n1) {
        int f = 1 - ans.back();
        for (int i = 1; i < n1; i++)
            ans.pb(f), f ^= 1;
    } else if ((n0 || n2) && n1) {
        int f = 1 - ans.back();
        for (int i = 1; i <= n1; i++)
            ans.pb(f), f ^= 1;
    } else if (n1) {
        int f = 1;
        for (int i = 0; i <= n1; i++)
            ans.pb(f), f ^= 1;
    }
    for (int i : ans) cout << i;
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
