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
    return fact[n] * invfact[k] * invfact[n - k];
}
vector<int> cnt(26, 0);
vector<ModInt> inv;
int all;
ModInt calc() {
    int tot = 0;
    ModInt ret = 1;
    for (int i : cnt) {
        tot += i;
        ret = ret * invfact[i];
    }
    ret = ret * fact[tot];
    return ret;
}
ModInt get(string& s, int ind = 0) {
    if (ind == s.size()) return 0;
    int c = s[ind] - 'a';
    ModInt ret = 0;
    ModInt fix = calc();
    for (int i = 0; i < c; i++) {
        if (cnt[i] == 0) continue;
        ret = ret + fix * cnt[i] * inv[all];
    }
    if (cnt[c] == 0) return ret;
    cnt[c]--, all--;
    ret = ret + get(s, ind + 1);
    cnt[c]++, all++;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b;
    cin >> a >> b;
    int n = a.size();
    all = n;
    factorials(n + 2);
    inv.assign(n + 2, 1);
    for (int i = 2; i <= n + 1; i++)
        inv[i] = lgpow(i);
    for (char c : a) cnt[c - 'a']++;
    ModInt ans = get(b) - get(a) - 1;
    cout << ans.get() << '\n';
}
