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
// const int kMod = 1e9 + 7;
struct ModInt {
    long long n;
    ModInt(long long n = 0) : n(n % kMod) {}
    ModInt operator+(const ModInt& oth) { return n + oth.n; }
    ModInt operator-(const ModInt& oth) { return n - oth.n; }
    ModInt operator*(const ModInt& oth) { return n * oth.n; }
    long long get() { return n < 0 ? n + kMod : n; }
    friend ostream& operator<<(ostream& os, ModInt const& a) { return os << ModInt(a.n).get(); }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), p(n + 1, 0);
    for (int& e : arr) cin >> e;
    sort(all(arr));
    for (int i = 0; i < n; i++)
        p[i + 1] = (p[i] + arr[i]) % kMod;
    vector<ModInt> inv(n + 1, 1);
    for (int i = 2; i <= n; i++)
        inv[i] = ModInt(kMod) - inv[kMod % i] * (kMod / i);
    while (m--) {
        int a, b;
        cin >> a >> b;
        int lt = lb(all(arr), b) - arr.begin();
        int gr = n - lt;
        ModInt ans = 0;
        if (a <= gr) {
            ans = inv[gr + 1] * p[lt] * (gr + 1 - a);
            if (gr > 0)
                ans = ans + inv[gr] * (p[n] - p[lt]) * (gr - a);
        }
        cout << ans.get() << '\n';
    }
}
