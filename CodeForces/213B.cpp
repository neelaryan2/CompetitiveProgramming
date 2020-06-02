/* Author - Neel Aryan (@neelaryan2) */
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

const int kMod = 1e9 + 7;
struct ModInt {
    long long n;
    ModInt(long long n = 0) : n(n % kMod) {}
    ModInt operator+(const ModInt& oth) { return n + oth.n; }
    ModInt operator-(const ModInt& oth) { return n - oth.n; }
    ModInt operator*(const ModInt& oth) { return n * oth.n; }
    long long get() { return n < 0 ? n + kMod : n; }
};
ModInt lgpow(ModInt b, int e = -1) {
    if (b.get() == 0) return 0;
    ModInt r;
    e = e % (kMod - 1);
    if (e < 0) e += kMod - 1;
    for (r = 1; e; e >>= 1, b = b * b)
        if (e & 1) r = r * b;
    return r;
}
vector<ModInt> fact, invfact;
void factorials(int n) {
    fact.resize(n + 1, 1);
    invfact.resize(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i;
    invfact[n] = lgpow(fact[n]);
    for (int i = n - 1; i >= 1; --i)
        invfact[i] = invfact[i + 1] * (i + 1);
}
ModInt choose(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    return fact[n] * invfact[k] * invfact[n - k];
}
int a[10];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    factorials(200);
    int n;
    cin >> n;
    for (int i = 0; i < 10; i++)
        cin >> a[i];
    ModInt dp[n + 1][10], res, ans = 0;
    for (int j = 9; j >= 0; j--) {
        for (int i = 0; i <= n; i++) {
            dp[i][j] = 0;
            if (j == 9)
                dp[i][j] = int(i >= a[j]);
            else if (j == 0) {
                for (int k = a[j]; k <= i; k++) {
                    res = choose(i - 1, k);
                    res = res * dp[i - k][j + 1];
                    dp[i][j] = dp[i][j] + res;
                }
            } else {
                for (int k = a[j]; k <= i; k++) {
                    res = choose(i, k);
                    res = res * dp[i - k][j + 1];
                    dp[i][j] = dp[i][j] + res;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        ans = ans + dp[i][0];
    cout << ans.get() << '\n';
}
