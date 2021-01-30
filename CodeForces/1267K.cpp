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

ll repr(vector<int>& a) {
    ll k = 0;
    for (int i = (int)a.size() - 1; i >= 0; i--)
        k = (i + 2) * k + a[i];
    return k;
}
bool valid(vector<int>& a) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] > i + 1) return false;
    return true;
}
vector<int> key(ll a) {
    vector<int> ret;
    for (int i = 2; a; i++) {
        ret.eb(a % i);
        a /= i;
    }
    return ret;
}
const int N = 19;
ll C[N + 1][N + 1];
void nCk() {
    memset(C, 0, sizeof C);
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= min(i, N); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}
void solve(int test) {
    ll k, n = 0;
    cin >> k;
    vector<int> cnt(20, 0);
    for (int e : key(k))
        cnt[e]++, n++;
    ll ans = 0;
    for (int z = 0, t = 1; z <= min(1, cnt[0]); z++, t *= -1) {
        int cum = z;
        ll cur = 1;
        for (int i = 19; i > 0; i--) {
            if (cnt[i] == 0) continue;
            int can = n + 1 - (i + cum);
            if (can < cnt[i]) {
                cur = 0;
                break;
            }
            cur *= C[can][cnt[i]];
            cum += cnt[i];
        }
        ans += t * cur;
    }
    trace(key(k), k, ans);
    cout << (ans - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("in.txt", "w", stderr);
    nCk();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
