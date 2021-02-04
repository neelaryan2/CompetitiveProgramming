/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef tree<pii, null_type, less<pii>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
const int N = 1e6 + 5;
vector<int> BIT(N, 0);
void add(int i, int x) {
    for (; i < BIT.size(); i += i & (-i)) BIT[i] += x;
}
int get(int i) {
    int sum = 0;
    for (; i > 0; i -= i & (-i)) sum += BIT[i];
    return sum;
}
// equivalent to calculating lower_bound on prefix sums array
int bit_search(int val) {  //using binary lifting
    int sum = 0, pos = 0, s = BIT.size();
    for (int i = log2(s); i >= 0; i--) {
        int d = (1 << i);
        if (pos + d < s && sum + BIT[pos + d] < val)
            sum += BIT[pos + d], pos += d;
    }
    return pos + 1;
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        add(x, 1);
    }
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        if (k > 0) {
            add(k, 1);
        } else {
            int p = bit_search(-k);
            add(p, -1);
        }
    }
    int p = bit_search(1);
    if (p == N) {
        cout << 0 << '\n';
        return;
    }
    cout << p << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
