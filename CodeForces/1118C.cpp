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
const int N = 1010;

void no() {
    cout << "NO";
}
void solve(int test) {
    int n;
    cin >> n;
    vector<int> cnt(N, 0);
    for (int i = 0; i < n * n; i++) {
        int e;
        cin >> e;
        cnt[e]++;
    }
    int a[n][n];
    memset(a, 0, sizeof a);
    if (n & 1) {
        vector<int> twos;
        for (int i = 0; i < N; i++) {
            if (cnt[i] & 1) {
                if (a[n / 2][n / 2])
                    return no();
                a[n / 2][n / 2] = i;
                cnt[i]--;
            }
            if ((cnt[i] / 2) & 1) {
                twos.eb(i);
            }
        }
        if (twos.size() % 2) return no();
        int ptr = 0, k = 1 + n / 2, p;
        for (p = 0; p < (n / 2); p++) {
            if (ptr == twos.size()) break;
            a[n / 2][p] = a[n / 2][n - 1 - p] = twos[ptr];
            cnt[twos[ptr++]] -= 2;
            a[p][n / 2] = a[n - p - 1][n / 2] = twos[ptr];
            cnt[twos[ptr++]] -= 2;
        }
        if (ptr != twos.size()) return no();
        for (int e = 0; e < N; e++) {
            if (p == n / 2) break;
            while (cnt[e]) {
                if (p == n / 2) break;
                a[n / 2][p] = a[n / 2][n - 1 - p] = e;
                a[p][n / 2] = a[n - p - 1][n / 2] = e;
                cnt[e] -= 4;
                p++;
            }
        }
        if (p != n / 2) return no();
    }
    int pt = 0;
    for (int e = 0; e < N; e++) {
        if (cnt[e] % 4) return no();
        while (cnt[e]) {
            int x = pt / (n / 2), y = pt % (n / 2);
            int x2 = n - x - 1, y2 = n - y - 1;
            a[x][y] = a[x2][y] = a[x][y2] = a[x2][y2] = e;
            cnt[e] -= 4, pt++;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
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
    }
}
