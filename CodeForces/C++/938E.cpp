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
// const int kMod = 998244353;
const int kMod = 1e9 + 7;
struct ModInt {
    long long n;
    ModInt(long long n = 0) : n(n % kMod) {}
    ModInt operator+(const ModInt& oth) { return n + oth.n; }
    ModInt operator-(const ModInt& oth) { return n - oth.n; }
    ModInt operator*(const ModInt& oth) { return n * oth.n; }
    long long get() { return n < 0 ? n + kMod : n; }
    friend ostream& operator<<(ostream& os, ModInt const& a) { return os << ModInt(a.n).get(); }
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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    map<int, int> cnt;
    ModInt fact = 1;
    for (int i = 0, e; i < n; i++) {
        cin >> e;
        cnt[e]++;
        fact = fact * (i + 1);
    }
    vector<ModInt> lef(n + 2, 1), righ(n + 2, 1);
    for (int i = 1; i < n + 2; i++)
        lef[i] = lef[i - 1] * i;
    righ[n] = n;
    for (int i = n - 1; i >= 1; i--)
        righ[i] = righ[i + 1] * i;
    vector<pii> v(rall(cnt));
    int sum = v[0].se;
    ModInt ans = 0;
    for (int i = 1; i < v.size(); i++) {
        sum += v[i].se;
        ans = ans + lef[sum - 1] * righ[sum + 1] * v[i].se * v[i].fi;
    }
    cout << ans << '\n';
}
