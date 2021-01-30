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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> mod = {-1, 998244353, 1000000007, 1000000009};
const int HS = 4;
// mod[0] = std::uniform_int_distribution<int>(1e8, 1e9)(rng);

struct ihash {
    static int add(int a, int b, int m) {
        a += b;
        if (a >= m) a -= m;
        return a;
    }
    static int sub(int a, int b, int m) {
        a -= b;
        if (a < 0) a += m;
        return a;
    }
    static int mul(int a, int b, int m) {
        return (1LL * a * b) % m;
    }
    static int lgpow(int a, int e, int m) {
        if (a == 0) return 0;
        e = e % (m - 1);
        if (e < 0) e += m - 1;
        int r = 1;
        for (; e; e >>= 1, a = mul(a, a, m))
            if (e & 1) r = mul(r, a, m);
        return r;
    }
    const static int p1 = 53, p2 = 73;

    vector<int> a;
    ihash() {
        a.assign(HS, 0);
        a[1] = 1;
    }
    ihash(long long x) {
        a.resize(HS);
        for (int i = 0; i < HS; i++)
            a[i] = (x % mod[i] + mod[i]) % mod[i];
        a[2] = mul(a[2], lgpow(p1, a[2], mod[2]), mod[2]);
        a[3] = mul(a[3], lgpow(p2, a[3], mod[3]), mod[3]);
    }
    ihash operator+(const ihash& oth) {
        ihash res;
        res.a[0] = add(a[0], oth.a[0], mod[0]);
        res.a[1] = mul(a[1], oth.a[1], mod[1]);
        res.a[2] = add(a[2], oth.a[2], mod[2]);
        res.a[3] = add(a[3], oth.a[3], mod[3]);
        return res;
    }
    ihash operator-(const ihash& oth) {
        ihash res;
        res.a[0] = sub(a[0], oth.a[0], mod[0]);
        res.a[1] = mul(a[1], lgpow(oth.a[1], -1, mod[1]), mod[1]);
        res.a[2] = sub(a[2], oth.a[2], mod[2]);
        res.a[3] = sub(a[3], oth.a[3], mod[3]);
        return res;
    }
    bool operator==(const ihash& oth) {
        for (int i = 0; i < HS; i++)
            if (a[i] != oth.a[i]) return false;
        return true;
    }
};

ihash id;
vector<vector<pii>> adj;
vector<vector<ihash>> dp;
int ans, n, m, k;

void dfs(int v, ihash hs) {
    if (v == k) {
        trace(hs.a);
        ans += (hs == id);
    } else {
        for (int i = 0; i <= v; i++)
            dfs(v + 1, hs + dp[v][i]);
    }
}
void solve(int test) {
    mod[0] = std::uniform_int_distribution<int>(1e8, 1e9)(rng);

    cin >> n >> m >> k;
    adj.assign(n, {});
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[--u].eb(w, v);
    }
    trace(adj);
    dp.assign(k, vector<ihash>(k, ihash()));
    id = ihash();
    for (int i = 0; i < n; i++) {
        sort(all(adj[i]));
        int c = (int)adj[i].size() - 1;
        for (int j = 0; j <= c; j++)
            dp[c][j] = dp[c][j] + ihash(adj[i][j].se);
        id = id + ihash(i + 1);
    }
    ans = 0;
    trace(dp[0][0].a);
    dfs(0, ihash());
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
