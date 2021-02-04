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

void add(vector<ll>& B, int i, int x) {
    int n = B.size();
    for (; i < n; i += i & (-i))
        B[i] = B[i] + x;
}
ll sum(vector<ll>& B, int i) {
    ll sum = 0;
    for (; i > 0; i -= i & (-i))
        sum = sum + B[i];
    return sum;
}
int bit_search(vector<ll>& B, ll val) {
    ll sum = 0, pos = 0, s = B.size();
    for (int i = log2(s); i >= 0; i--) {
        int d = (1 << i);
        if (pos + d < s && sum + B[pos + d] < val) {
            pos = pos + d;
            sum = sum + B[pos];
        }
    }
    return pos + 1;
}
ll f(int n) {
    return (1LL * n * (n + 1)) / 2;
}
void solve(int test) {
    int n;
    cin >> n;

    vector<int> p(n + 1), q(n + 1), inv(n + 1, 0);
    vector<ll> B1(n + 1, 0), B2(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        q[p[i]] = i;
    }
    for (int i = n; i > 0; i--) {
        inv[p[i]] = sum(B1, p[i]);
        add(B1, p[i], 1);
    }
    ll inversions = 0, tot = 0;
    B1.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        inversions += inv[i];
        tot += q[i];
        add(B1, q[i], 1);
        add(B2, q[i], q[i]);
        ll nl = (1 + i) / 2, nr = i - (i + 1) / 2;
        int mid = bit_search(B1, nl);
        ll tmp = sum(B2, mid), cur = inversions;
        cur += nl * mid - tmp - f(nl - 1);
        cur += tot - tmp - nr * mid - f(nr);
        cout << cur << ' ';
    }
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
