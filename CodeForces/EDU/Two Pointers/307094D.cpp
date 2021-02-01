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
const int K = 4;
const int N = 1e5 + 5;

int n[K], ans[K];
vector<int> a[K];
int mx;

bool good(int b1, int i1, int b2, int i2) {
    int cur = a[b1][i1] - a[b2][i2];
    if (cur < 0) return false;
    for (int i = 0; i < K; i++) {
        if (i == b1 || i == b2) continue;
        int j = lb(all(a[i]), a[b2][i2]) - a[i].begin();
        if (j == n[i] || a[i][j] > a[b1][i1])
            return false;
    }
    if (cur < mx) {
        ans[b1] = a[b1][i1];
        ans[b2] = a[b2][i2];
        for (int i = 0; i < K; i++) {
            if (i == b1 || i == b2) continue;
            int j = lb(all(a[i]), a[b2][i2]) - a[i].begin();
            if (cur < mx) ans[i] = a[i][j];
        }
        mx = cur;
    }
    return true;
}

void solve(int test) {
    for (int i = 0; i < K; i++) {
        cin >> n[i];
        a[i].resize(n[i]);
        for (int& e : a[i]) cin >> e;
        sort(all(a[i]));
        ans[i] = -1;
    }
    mx = inf;
    for (int b1 = 0; b1 < K; b1++) {
        for (int b2 = 0; b2 < K; b2++) {
            if (b1 == b2) continue;
            int ptr = 0;
            for (int i = 0; i < n[b1]; i++)
                while (ptr < n[b2] && good(b1, i, b2, ptr))
                    ptr++;
        }
    }
    for (int i = 0; i < K; i++)
        cout << ans[i] << ' ';
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
