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
template <typename T>
struct sparse_table {
    int n = 0, levels = 0;
    vector<vector<T>> table;
    sparse_table(const vector<T> &values = {}) {
        if (!values.empty())
            build(values);
    }
    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }
    T func(T a, T b) const {
        return __gcd(a, b);
        return (a < b) ? a : b;
    }
    void build(const vector<T> &values) {
        n = int(values.size());
        levels = largest_bit(n) + 1;
        table.resize(levels);
        table[0] = values;
        for (int k = 1; k < levels; k++)
            table[k].resize(n - (1 << k) + 1);
        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                table[k][i] = func(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
    }
	// NOTE : range is [a, b)
    T query1(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = largest_bit(b - a);
        return func(table[level][a], table[level][b - (1 << level)]);
    }
	// NOTE : range is [a, b)
    T query2(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        T res = 0;
        for (int j = levels - 1; j >= 0; j--) {
            if ((1 << j) <= b - a) {
                res = func(res, table[j][a]);
                a += (1 << j);
            }
        }
        return res;
    }
};
const int inf = 1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, cnt = 0;
    cin >> n;
    vector<int> a(n);
    for (int &e : a) {
        cin >> e;
        if (e == 1) cnt++;
    }
    if (cnt > 0) {
        cout << n - cnt << '\n';
        return 0;
    }
    sparse_table<int> st(a);
    int seg = inf;
    for (int i = 0; i < n; i++) {
        if (st.query2(i, n) != 1) continue;
        int lo = i, hi = n, mid;
        while (lo < hi - 1) {
            mid = lo + (hi - lo) / 2;
            if (st.query2(i, mid) == 1)
                hi = mid;
            else
                lo = mid;
        }
        seg = min(seg, hi - i);
    }
    seg += n - 2;
    if (seg >= inf - 1) seg = -1;
    cout << seg << '\n';
}
