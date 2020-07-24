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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<ll> B(n + 10, 0);
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            l++, r++;
            add(B, l, v);
            add(B, r, -v);
        }
        if (t == 2) {
            int i;
            cin >> i;
            i++;
            cout << sum(B, i) << '\n';
        }
    }
}
