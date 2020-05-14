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
const int B = 30;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m), q(m);
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> q[i];
    }
    vector<int> ans(n, 0);
    for (int b = B - 1; b >= 0; b--) {
        vector<int> cur(n + 2, 0), tmp(n + 2, 0);
        for (int i = 0; i < m; i++) {
            if ((q[i] >> b) & 1) {
                tmp[l[i]]++;
                tmp[r[i] + 1]--;
            }
        }
        for (int i = 1; i <= n + 1; i++)
            tmp[i] += tmp[i - 1];

        for (int i = 1; i <= n + 1; i++) {
            if (tmp[i] < 1) continue;
            tmp[i] = 1;
            ans[i - 1] += (1 << b);
        }
        for (int i = 1; i <= n; i++)
            tmp[i] += tmp[i - 1];

        for (int i = 0; i < m; i++) {
            if ((q[i] >> b) & 1) continue;
            int cnt = tmp[r[i]] - tmp[l[i] - 1];
            if (cnt == r[i] - l[i] + 1) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for (int i : ans) cout << i << " ";
    cout << '\n';
}
