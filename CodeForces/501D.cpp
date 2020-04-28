#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
using ll = long long;
using pii = pair<int, int>;
using ppi = pair<int, pii>;
using vpi = vector<pii>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define runtime() (int)(1000 * ((double)clock()) / CLOCKS_PER_SEC)
using vi = vector<int>;

vi getPos(vi const& p) {
    ordered_set s;
    int n = p.size();
    for (int i = 0; i < n; i++)
        s.insert(i);
    vi pos;
    for (int i : p) {
        pos.pb(s.order_of_key(i));
        s.erase(i);
    }
    return pos;
}
vi build(vi const& pos) {
    ordered_set s;
    int n = pos.size();
    for (int i = 0; i < n; i++)
        s.insert(i);
    vi p;
    for (int i : pos) {
        auto it = s.find_by_order(i);
        p.pb(*it);
        s.erase(it);
    }
    return p;
}
vi sum(vi const& pos1, vi const& pos2) {
    int n = pos1.size();
    assert(pos2.size() == n);
    vi pos(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        pos[i] += pos1[i] + pos2[i];
        if (i > 0) pos[i - 1] += pos[i] / (n - i);
        pos[i] %= (n - i);
    }
    return pos;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> p1(n), p2(n);
    for (int& e : p1) cin >> e;
    for (int& e : p2) cin >> e;
    vi pos1 = getPos(p1);
    // for (int i : pos1) cout << i << ' ';
    // cout << '\n';
    vi pos2 = getPos(p2);
    // for (int i : pos2) cout << i << ' ';
    // cout << '\n';
    vi pos = sum(pos1, pos2);
    // for (int i : pos) cout << i << ' ';
    // cout << '\n';
    vi p = build(pos);
    for (int i : p) cout << i << ' ';
    cout << '\n';
}