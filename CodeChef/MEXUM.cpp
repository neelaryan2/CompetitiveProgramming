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

const int kMod = 998244353;
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
    int n;
    cin >> n;
    vector<int> cnt(n + 2, 0);
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        if (e <= n) cnt[e]++;
    }
    ModInt suf = lgpow(2, n);
    ModInt ans = 0, pref = 1;
    for (int i = 1; i <= n; i++) {
        suf = suf * lgpow(2, -cnt[i]);
        ans = ans + pref * suf * i;
        pref = pref * (lgpow(2, cnt[i]) - 1);
        if (cnt[i] == 0) break;
    }
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