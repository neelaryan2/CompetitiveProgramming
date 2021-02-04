#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
using pii = pair<int, int>;
using ll = long long;
const int N = 3e4 + 10;
const int R = 2e2 + 50;
int n, d;
int dp[N][2 * R], cnt[N];
int calc(int i, int j) {
    int off = R - d;
    if (j == 0) return 0;
    if (i >= N || j + off >= 2 * R || j + off < 0) return 0;
    int& c = dp[i][j + off];
    if (c != -1) return c;
    for (int k = -1; k < 2; k++)
        c = max(c, calc(i + j + k, j + k));
    c += cnt[i];
    return c;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        cnt[e]++;
    }
    int ans = calc(d, d);
    cout << ans << '\n';
}