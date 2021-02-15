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
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;
const int B = 30, g = 3;
const int kMod = 998244353;

int mul(int a, int b) {
    return (1LL * a * b) % kMod;
}
int add(int a, int b) {
    a += b;
    if (a >= kMod) a -= kMod;
    return a;
}
int sub(int a, int b) {
    a -= b;
    if (a < 0) a += kMod;
    return a;
}
int lgpow(int b, int e = -1) {
    if (b == 0) return 0;
    if (e < 0) e += kMod - 1;
    int r = 1;
    for (; e; e >>= 1, b = mul(b, b))
        if (e & 1) r = mul(r, b);
    return r;
}

vector<int> fact, invfact;
void factorials(int n) {
    fact.assign(n + 1, 1);
    invfact.assign(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        fact[i] = mul(fact[i - 1], i);
    invfact[n] = lgpow(fact[n]);
    for (int i = n - 1; i >= 1; --i)
        invfact[i] = mul(invfact[i + 1], (i + 1));
}
int choose(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

vector<int> rev({0, 1});
vector<int> rt(2, 1);

void init(int n) {
    int rts = rt.size();
    if (n <= rts) return;
    rev.resize(n);
    for (int i = 0; i < n; i++)
        rev[i] = (rev[i >> 1] | ((i & 1) * n)) >> 1;
    rt.reserve(n);
    for (int k = rts; k < n; k *= 2) {
        rt.resize(2 * k);
        int z = lgpow(g, (kMod - 1) / (2 * k));
        for (int i = k / 2; i < k; i++)
            rt[2 * i] = rt[i], rt[2 * i + 1] = mul(rt[i], z);
    }
}
void fft(vector<int>& a, int n) {
    init(n);
    int s = rev.size();
    s = __builtin_ctz(s / n);
    for (int i = 0; i < n; i++)
        if (i < (rev[i] >> s))
            swap(a[i], a[rev[i] >> s]);
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                int t = mul(rt[j + k], a[i + j + k]);
                a[i + j + k] = sub(a[i + j], t);
                a[i + j] = add(a[i + j], t);
            }
        }
    }
}
void multiply(vector<int>& a, vector<int>& b) {
    int sza = a.size();
    int szb = b.size();
    int s = sza + szb - 1;
    if (s <= 0) return;
    int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;
    a.resize(n, 0), b.resize(n, 0);
    fft(a, n), fft(b, n);
    int d = lgpow(n);
    for (int i = 0; i < n; i++)
        a[i] = mul(mul(a[i], b[i]), d);
    reverse(a.begin() + 1, a.end());
    fft(a, n);
}

vector<int> a, cnt, ans;
vector<int> dp[B];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    a.resize(n);
    factorials(n);
    cnt.assign(B, 0);
    for (int& e : a) {
        cin >> e;
        for (int b = 0; b < B; b++)
            if ((e >> b) & 1) cnt[b]++;
    }
    ans.assign(n + 1, 0);
    vector<int> dp, vec;
    int cur = 1;

    for (int k : cnt) {
        if (k == 0) continue;

        dp.assign(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n - k; i++)
            dp[i] = add(dp[i - 1], choose(n - k, i));
        for (int i = n - k + 1; i <= n; i++)
            dp[i] = dp[i - 1];

        vec.assign(k + 1, 0);
        for (int i = 0; i <= k; i++)
            if (i & 1)
                vec[i] = choose(k, i);

        multiply(dp, vec);
        for (int i = 0; i <= n; i++)
            ans[i] = add(ans[i], mul(dp[i], cur));
        cur <<= 1;
    }
    int m, q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> m;
        cout << ans[m] << '\n';
    }
}
