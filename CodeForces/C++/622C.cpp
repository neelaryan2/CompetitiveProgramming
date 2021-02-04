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
vector<vi> ind(1e6 + 1);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int e;
        cin >> e;
        ind[e].pb(i);
    }
    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        int lo = lower_bound(all(ind[x]), l) - ind[x].begin();
        int hi = lower_bound(all(ind[x]), r) - ind[x].begin() + 1;
        int base = lo, sz = ind[x].size();
        if (lo == sz || ind[x][lo] != l) {
            cout << l << '\n';
            continue;
        }
        if (hi - 1 == sz || ind[x][hi - 1] != r) {
            cout << r << '\n';
            continue;
        }
        while (lo < hi - 1) {
            int mid = (lo + hi) / 2;
            if (ind[x][mid] == mid - base + l)
                lo = mid;
            else
                hi = mid;
        }
        int ans = ind[x][lo] + 1;
        if (ans == r + 1) ans = -1;
        cout << ans << '\n';
    }
}
