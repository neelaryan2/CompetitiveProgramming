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
void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> k(n);
    for (int& e : k) cin >> e;
    if (p == 1) {
        cout << (n & 1) << '\n';
        return;
    }
    sort(all(k));
    ll sum = 1;
    int i, prv = k[n - 1];
    ld logp = log(p);
    for (i = n - 2; i >= 0; i--) {
        int cur = prv - k[i];
        ld tmp = ((ld)i + 1) / sum;
        if (cur * logp >= log(tmp)) 
            break;
        sum *= lgpow(p, cur).get();
        if (sum > 0)
            sum--;
        else
            sum++;
        prv = k[i];
    }
    ModInt ans = lgpow(p, prv) * sum;
    for (int j = i; j >= 0; j--)
        ans = ans - lgpow(p, k[j]);
    cout << ans.get() << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
