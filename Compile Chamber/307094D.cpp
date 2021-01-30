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
int n[K];
vector<int> a[K];

bool good(int b1, int b2) {
    for (int i = 0; i < K; i++) {
        if (i == b1 || i == b2) continue;
        a[i]
    }
}

void solve(int test) {
    for (int i = 0; i < K; i++) {
        cin >> n[i];
        a[i].resize(n[i]);
        for (int& e : a[i] ) cin >> e;
        sort(all(a[i]));
    }
    for (int b1 = 0; b1 < K; b1++) {
        for (int b2 = b1 + 1; b2 < K; b2++) {
            int ptr = 0;
            for (int i = 0; i < n; i++) {
                while (ptr < n && a[b1][i] <= a[b2][ptr] && !good(b1, b2))
                    ptr++;
                if (good(b1, b2) && a[b2][ptr] - a[b1][i] < ans) {
                    ans = a[b2][ptr] - a[b1][i];



                }
            }
        }
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
