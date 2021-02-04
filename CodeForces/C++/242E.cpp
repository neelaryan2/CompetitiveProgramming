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
const int B = 20;
struct decomp {
    vector<int> state, block, sums;
    int n, rt;
    decomp(int m) {
        n = m;
        rt = sqrtl(n) + 1;
        block.assign(rt + 1, 0);
        sums.assign(rt + 1, 0);
        state.assign(n, 0);
    }
    void update(int i, int j) {
        if (i > j) return;
        if (i < 0) return update(0, j);
        if (j >= n) return update(i, n - 1);
        int ri = i / rt, rj = j / rt;
        if (ri == rj) {
            for (int it = i; it <= j; it++) {
                state[it] = 1 - state[it];
                int ch = 2 * state[it] - 1;
                sums[ri] += block[ri] ? -ch : ch;
            }
            return;
        }
        for (int it = ++ri; it < rj; it++) {
            sums[it] = rt - sums[it];
            block[it] = 1 - block[it];
        }
        update(i, ri * rt - 1);
        update(rj * rt, j);
    }
    int query(int i, int j) {
        if (i > j) return 0;
        if (i < 0) return query(0, j);
        if (j >= n) return query(i, n - 1);
        int ri = i / rt, rj = j / rt;
        int ans = 0;
        if (ri == rj) {
            for (int it = i; it <= j; it++)
                ans += block[ri] ? (1 - state[it]) : state[it];
            return ans;
        }
        for (int it = ++ri; it < rj; it++)
            ans += sums[it];
        ans += query(i, ri * rt - 1);
        ans += query(rj * rt, j);
        return ans;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<decomp> vec(B, decomp(n));
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        for (int j = 0; j < B; j++) {
            int b = (e >> j) & 1;
            if (b) vec[j].update(i, i);
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r, x, t;
        cin >> t >> l >> r;
        --l, --r;
        if (t == 1) {
            ll ans = 0;
            for (int j = 0, pw = 1; j < B; j++, pw <<= 1) {
                int s = vec[j].query(l, r);
                ans += 1LL * s * pw;
            }
            cout << ans << '\n';
        } else {
            cin >> x;
            for (int j = 0; j < B; j++) {
                int b = (x >> j) & 1;
                if (b) vec[j].update(l, r);
            }
        }
    }
}
