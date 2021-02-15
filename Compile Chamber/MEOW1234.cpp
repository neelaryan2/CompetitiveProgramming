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

const int mod = 1e9 + 7;
const int N = 1e5 + 1;

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}
int add(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}
int lgpow(int b, int e = -1) {
    if (b == 0) return 0;
    if (e < 0) e += mod - 1;
    int r = 1;
    for (; e; e >>= 1, b = mul(b, b))
        if (e & 1) r = mul(r, b);
    return r;
}
int divd(int a, int b) {
    return mul(a, lgpow(b));
}
int sub(int a, int b) {
    a -= b;
    if (a < 0) a += mod;
    return a;
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

struct pt {
    int x, y;
    pt(int _x = 0, int_y = 0) {
        x = _x, y = _y;
    }
};
vector<vi> byx(N);
vector<vector<pt>> byy(N);
void solve(int test) {
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        byx[x].eb(y);
    }
    ll ans = 0;
    for (int x = 0; x < N; x++) {
        vi& v = byx[x];
        if (v.empty()) continue;
        int mn = N, mx = -N, cnt = 0;
        for (int& y : v) {
            mn = min(mn, y);
            mx = max(mx, y);
            cnt++;
        }
        v.clear();
        ans += (mx - mn + 1) - cnt;
        byy[mn].eb(pt(x, mx));
    }
    for (int i = 0; i < N; i++) {
        vector<pt>& v = byy[i];
        if (v.empty()) continue;
        map<int, pii> cur;
        for (pt& p : v) {
            auto it = cur.find(-p.y);
            if (it == cur.end())
                cur[-p.y] = mp(p.x, p.x);
            else
                (it->se).se = p.x;
        }

        int mx = i, cnt = 0;
        int range = v.back().x - v[0].x + 1;
        for (pt& p : v)
            mx = max(mx, p.y);
        int sndmx = -N;
        for (pt& p : v) {
            if (p.y == mx)
                cnt++;
            else
                sndmx = max(sndmx, p.y);
        }
        if (cnt > 1 || (cnt == 1 && sndmx == -N)) {
            ll cur = range for (pt& p : v) {
                ans += mx - p.y;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    factorials(N - 1);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
