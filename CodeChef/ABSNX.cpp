/* Author - Neel Aryan (@neelaryan2) */
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the iterator to kth largest element.(0-based)

vi prevGreater(vector<int>& a) {
    int n = a.size();
    vector<int> prv(n, -1);
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; i++) {
        while (!s.empty() && a[s.top()] <= a[i])
            s.pop();
        if (!s.empty()) prv[i] = s.top();
        s.push(i);
    }
    return prv;
}
ll get(vector<int>& a) {
    int n = a.size();
    ordered_set st;
    vi prv = prevGreater(a);
    stack<int> s;
    s.push(0);
    st.insert(0);
    ll ans = 1;
    trace(prv);
    for (int i = 1; i < n; i++) {
        while (!s.empty() && a[s.top()] > a[i]) {
            st.erase(s.top());
            s.pop();
        }
        st.insert(i);
        s.push(i);
        trace(vector<int>(all(st)));
        int t = st.order_of_key(prv[i] + 1);
        ans += st.size() - t;
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    ll ans = get(a);
    trace(ans);
    for (int i = 0; i < n; i++) {
        ll count = 1;
        while (i < n - 1 && a[i] == a[i + 1]) {
            count++;
            i++;
        }
        ans -= (count * (count + 1)) / 2;
    }
    for (int& e : a) e = -e;
    ans += get(a);
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
