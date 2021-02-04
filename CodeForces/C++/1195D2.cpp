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
const int kMod = 998244353;
struct ModInt {
    long long n;
    ModInt(long long n = 0) : n(n % kMod) {}
    ModInt operator+(const ModInt& oth) { return n + oth.n; }
    ModInt operator-(const ModInt& oth) { return n - oth.n; }
    ModInt operator*(const ModInt& oth) { return n * oth.n; }
    long long get() { return n < 0 ? n + kMod : n; }
};
ModInt f(vi& a, vi& b) {
    int n = a.size(), m = b.size();
    int l = 0, r = 0, t = 0;
    ModInt pw = 1, ret = 0;
    while (t < 2 * min(n, m)) {
        ret = ret + pw * b[r++];
        pw = pw * 10, t++;
        ret = ret + pw * a[l++];
        pw = pw * 10, t++;
    }
    while (r != m) {
        ret = ret + pw * b[r++];
        pw = pw * 10, t++;
    }
    while (l != n) {
        ret = ret + pw * a[l++];
        pw = pw * 10, t++;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vi cnt(11, 0);
    vector<vi> a(n);
    for (int i = 0, e; i < n; i++) {
        cin >> e;
        int c = 0;
        while (e) {
            a[i].pb(e % 10);
            e /= 10, c++;
        }
        cnt[c]++;
    }
    ModInt ans = 0, res;
    for (int d = 1; d <= 10; d++) {
        vi tmp(d, 0);
        for (int i = 0; i < n; i++) {
            res = f(tmp, a[i]) + f(a[i], tmp);
            res = res * cnt[d];
            ans = ans + res;
        }
    }
    cout << ans.get() << '\n';
}
