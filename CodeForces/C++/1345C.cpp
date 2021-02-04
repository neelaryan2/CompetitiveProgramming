#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        e = (e + i) % n;
        if (e < 0) e += n;
        vis[e] = true;
    }
    bool f = true;
    for (bool b : vis)
        f = f && b;
    puts(f ? "YES" : "NO");
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
