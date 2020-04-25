#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ppi = pair<pii, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
int N = 5e5 + 10;

const int kMod = 998244353;
struct ModInt {
    long long n;
    ModInt(long long n = 0) : n(n % kMod) {}
    ModInt operator+(const ModInt& oth) { return n + oth.n; }
    ModInt operator-(const ModInt& oth) { return n - oth.n; }
    ModInt operator*(const ModInt& oth) { return n * oth.n; }
    long long get() { return n < 0 ? n + kMod : n; }
};

vector<ModInt> B1, B2;
void add(vector<ModInt>& b, int idx, ModInt x) {
    while (idx <= N) {
        b[idx] = b[idx] + x;
        idx += idx & -idx;
    }
}
void range_add(int l, int r, ModInt x) {
    if (r < l) return;
    ModInt neg = x - x * 2;
    add(B1, l, x);
    add(B1, r + 1, neg);
    add(B2, l, x * (l - 1));
    add(B2, r + 1, neg * r);
}
ModInt sum(vector<ModInt>& b, int idx) {
    ModInt total = 0;
    while (idx > 0) {
        total = total + b[idx];
        idx -= idx & -idx;
    }
    return total;
}
ModInt prefix_sum(int idx) {
    return sum(B1, idx) * idx - sum(B2, idx);
}
ModInt range_sum(int l, int r) {
    if (r < l) return 0;
    return prefix_sum(r) - prefix_sum(l - 1);
}
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    N = m + 10;
    B1.assign(N, 0);
    B2.assign(N, 0);
    vector<ModInt> arr(n, 0);
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        arr[i] = e;
    }
    int oth = n + 1 - m;
    ModInt sum = 0;
    int ind = 0;
    for (int i = 0; i < oth; i++)
        sum = sum + arr[i];
    ModInt ans = 0;
    for (int i = 0; i < m; i++) {
        range_add(i + 1, i + 1, sum);
        ans = ans + sum * sum;
        if (i == m - 1) continue;
        sum = sum + arr[oth + i] - arr[i];
    }
    for (int i = 0; i < q; i++) {
        int pos, val;
        cin >> pos >> val;
        ModInt x = ModInt(val) - arr[pos - 1];
        arr[pos - 1] = val;
        int l = max(pos - n + m, 1);
        int r = min(m, pos);
        ModInt upd = range_sum(l, r);
        range_add(l, r, x);
        ans = ans + upd * x * 2;
        ans = ans + x * x * (r - l + 1);
        cout << ans.get() << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}