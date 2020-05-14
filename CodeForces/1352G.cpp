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
    int n;
    cin >> n;
    if (n <= 3) {
        cout << "-1\n";
        return;
    }
    if (n == 4) {
        cout << "3 1 4 2\n";
        return;
    }
    vector<int> ans;
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i += 2) {
        ans.pb(i);
        vis[i] = true;
    }
    vis[ans.back() - 3] = true;
    ans.pb(ans.back() - 3);
    for (int i = n; i >= 1; i--)
        if (!vis[i])
            ans.pb(i);
    for (int i : ans) cout << i << " ";
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
