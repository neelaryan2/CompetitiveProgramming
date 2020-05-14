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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vi> s(n), dp1(n), dp2(n + 1, vi(m + 1, 0));
    for (int i = 0; i < n; i++) {
        int sz;
        cin >> sz;
        s[i].assign(sz + 1, 0);
        dp1[i].assign(sz + 1, 0);
        for (int j = 1; j <= sz; j++) {
            cin >> s[i][j];
            s[i][j] += s[i][j - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        int sz = s[i].size() - 1;
        for (int j = 0; j <= sz; j++) {
            for (int k = 0; k <= j; k++) {
                dp1[i][j] = max(dp1[i][j], s[i][j - k] + s[i][sz] - s[i][sz - k]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < s[i - 1].size(); k++) {
            for (int j = k; j <= m; j++) {
                dp2[i][j] = max(dp2[i][j], dp2[i - 1][j - k] + dp1[i - 1][k]);
            }
        }
    }
    cout << dp2[n][m] << endl;
}
