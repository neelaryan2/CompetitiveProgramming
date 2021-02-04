#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<ld>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
vector<vi> dp;
ld solve(int w, int b) {
    if (w < 0 || b < 0) return 0;
    ld& c = dp[w][b];
    if (c >= 0) return c;
    if (w == 0) return c = 0;
    if (b == 0) return c = 1;
    ld c1 = solve(w - 1, b - 2);
    ld c2 = solve(w, b - 3);
    int k = b + w;
    if (k == 2) return c = 0.5;
    c = (w * c1 + (b - 2) * c2) / (k - 2);
    c *= ((ld)b * (b - 1)) / (k * (k - 1));
    c += (ld)w / k;
    return c;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int w, b;
    cin >> w >> b;
    dp.assign(w + 1, vi(b + 1, -1));
    ld ans = solve(w, b);
    cout << fixed << setprecision(9) << ans << '\n';
}
