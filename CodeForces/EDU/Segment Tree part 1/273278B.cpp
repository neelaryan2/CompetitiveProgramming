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
vector<int> B1, B2;
void add(vector<int>& B, int i, int x) {
    int n = B.size();
    for (; i < n; i += i & (-i))
        B[i] = B[i] + x;
}
int bit_search(vector<int>& B, int val) {
    int sum = 0, pos = 0, s = B.size();
    for (int i = log2(s); i >= 0; i--) {
        int d = (1 << i);
        if (pos + d < s && sum + B[pos + d] < val) {
            pos = pos + d;
            sum = sum + B[pos];
        }
    }
    return pos + 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> B(n + 10, 0), a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i]) add(B, i + 1, 1);
    }
    while (m--) {
        int t, k;
        cin >> t >> k;
        if (t == 1) {
            add(B, k + 1, 1 - 2 * a[k]);
            a[k] ^= 1;
        }
        if (t == 2) {
            int c = bit_search(B, k + 1);
            cout << c - 1 << '\n';
        }
    }
}
