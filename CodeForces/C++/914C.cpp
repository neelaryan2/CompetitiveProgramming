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
const int N = 1000;
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
vector<vi> adj;
vector<int> dist;
void dfs(int v, int d = 0) {
    dist[v] = d;
    for (int u : adj[v])
        dfs(u, d + 1);
}
ModInt get(const string& s, int bits) {
    int n = s.size(), cnt1 = 0;
    ModInt ret = 0;
    for (int j = 0; j < n; j++) {
        if (s[j] == '1') {
            ret = ret + choose(n - 1 - j, bits - cnt1);
            cnt1++;
        }
    }
    ret = ret + (cnt1 == bits);
    return ret;
}
string toBinary(int n) {
    string r;
    while (n) {
        r += (n & 1) ? '1' : '0';
        n >>= 1;
    }
    reverse(all(r));
    return r;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    factorials(1010);
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size() + 1;
    string tmp = toBinary(n - 1);
    vector<ModInt> cnt(n, 0);
    for (int i = 0; i < n; i++)
        cnt[i] = get(s, i) - get(tmp, i);
    adj.resize(n);
    dist.assign(n, 1e9);
    for (int i = 2; i < n; i++) {
        int c = __builtin_popcount(i);
        adj[c].eb(i);
    }
    dfs(1);
    ModInt ans = 0;
    for (int i = 1; i < n; i++) {
        if (dist[i] == k) ans = ans + 1;
        if (dist[i] == k - 1) ans = ans + cnt[i];
    }
    cout << ans.get() << '\n';
}
