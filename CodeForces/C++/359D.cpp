#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
vector<int> arr;
struct segtree {
    vector<int> t;
    int n;
    segtree() {}
    int combine(int a, int b) {
        return max(a, b);
    }
    void build(vector<int>& a) {
        n = a.size();
        t.resize(2 * n);
        for (int i = 0; i < n; i++)
            t[i + n] = a[i];
        for (int i = n - 1; i > 0; i--)
            t[i] = combine(t[i << 1], t[i << 1 | 1]);
    }
    void update(int p, int x) {  // on 0-indexed p
        for (t[p += n] = x; p >>= 1;)
            t[p] = combine(t[p << 1], t[p << 1 | 1]);
    }
    int query(int l, int r) {  // interval [l,r]
        int resl = 0, resr = 0;
        for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) resl = combine(resl, t[l++]);
            if (r & 1) resr = combine(t[r--], resr);
        }
        return combine(resl, resr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    arr.resize(n);
    for (int& a : arr) cin >> a;
    segtree tree;
    tree.build(arr);
    vector<int> left(n), right(n);
    int lo, hi, mid, g;
    for (int i = 0; i < n; i++) {
        lo = -1, hi = i;
        while (lo < hi - 1) {
            mid = lo + (hi - lo) / 2;
            g = tree.query(mid, i);
            if (g % arr[i] == 0)
                hi = mid;
            else
                lo = mid;
        }
        left[i] = hi;
        lo = i, hi = n;
        while (lo < hi - 1) {
            mid = lo + (hi - lo) / 2;
            g = tree.query(i, mid);
            if (g % arr[i] == 0)
                lo = mid;
            else
                hi = mid;
        }
        right[i] = lo;
    }
    int mx = -1;
    for (int i = 0; i < n; i++)
        mx = max(mx, right[i] - left[i]);
    set<int> ans;
    for (int i = 0; i < n; i++)
        if (right[i] - left[i] == mx)
            ans.insert(left[i] + 1);
    cout << ans.size() << ' ' << mx << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}