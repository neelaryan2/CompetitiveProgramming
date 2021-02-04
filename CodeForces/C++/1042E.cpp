/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

const int mod = 998244353;
int add(int a, int b) {
    a = a + b;
    if (a >= mod) a -= mod;
    if (a < 0) a += mod;
    return a;
}
int mul(int a, int b) {
    a = (1LL * a * b) % mod;
    if (a < 0) a += mod;
    return a;
}
int lgpow(int b, int e = -1) {
    if (b == 0) return 0;
    e = e % (mod - 1);
    if (e < 0) e += mod - 1;
    int r = 1;
    while (e) {
        if (e & 1) r = mul(r, b);
        e >>= 1, b = mul(b, b);
    }
    return r;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int nm = n * m;
    vector<int> g(nm);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int v = i * m + j;
            cin >> g[v];
        }
    }
    int r, c;
    cin >> r >> c;
    r--, c--;
    int s = r * m + c;
    vector<int> vec(1, s);
    for (int i = 0; i < nm; i++) {
        if (g[i] < g[s])
            vec.pb(i);
    }
    sort(all(vec), [&g](int i, int j) {
        return g[i] < g[j];
    });
    int k = vec.size();
    vector<int> dp(k, 0);
    int sum, sumx, sumy, sumx2, sumy2, sumdp;
    sum = sumx = sumy = sumx2 = sumy2 = sumdp = 0;
    for (int i = 0; i < k;) {
        int r = i;
        int tmp, tmpx, tmpy, tmpx2, tmpy2, tmpdp;
        tmp = tmpx = tmpy = tmpx2 = tmpy2 = tmpdp = 0;
        while (r < k && g[vec[r]] == g[vec[i]]) r++;
        int invi = lgpow(i);
        for (int j = i; j < r; j++) {
            int x = vec[j] / m;
            int y = vec[j] % m;
            if (i) {
                dp[j] = add(dp[j], sumdp);
                dp[j] = add(dp[j], sumx2);
                dp[j] = add(dp[j], sumy2);
                dp[j] = add(dp[j], -mul(2 * x, sumx));
                dp[j] = add(dp[j], -mul(2 * y, sumy));
                dp[j] = mul(dp[j], invi);
                dp[j] = add(dp[j], add(mul(x, x), mul(y, y)));
            }
            tmpx = add(tmpx, x);
            tmpy = add(tmpy, y);
            tmpx2 = add(tmpx2, mul(x, x));
            tmpy2 = add(tmpy2, mul(y, y));
            tmpdp = add(tmpdp, dp[j]);
        }
        sumx = add(sumx, tmpx);
        sumy = add(sumy, tmpy);
        sumx2 = add(sumx2, tmpx2);
        sumy2 = add(sumy2, tmpy2);
        sumdp = add(sumdp, tmpdp);
        i = r;
    }
    cout << dp.back() << '\n';
}
