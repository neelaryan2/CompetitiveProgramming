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
const int mod = 1e9 + 7;
const int N = 3e5 + 5;
int cur, mid, bottom, top, n, q;
string rows[N];
vector<vi> ans, mans;
vector<vi> stor[N];
inline void adder(int& a, int b) {
    a = a + b;
    if (a >= mod) a -= mod;
}
inline void reset(vector<vi>& v) {
    if (v.empty()) {
        v.assign(n, vi(n, 0));
        return;
    }
    for (auto& x : v)
        memset(&x[0], 0, sizeof(int) * x.size());
}
void add() {
    string l;
    cin >> l;
    if (cur > bottom) {
        cur = 0;
        bottom = 0;
        mid = -1;
        rows[cur] = l;
        top = 0;
        reset(mans);
        for (int i = 0; i < n; i++)
            mans[i][i] = 1;
        return;
    }
    vector<vi> upd(n, vi(n, 0));
    string r = rows[bottom];
    for (int j = 0; j < n; j++) {
        if (l[j] == r[j])
            for (int i = 0; i < n; i++)
                adder(upd[i][j], mans[i][j]);

        if (j < n - 1 && r[j + 1] == l[j])
            for (int i = 0; i < n; i++)
                adder(upd[i][j], mans[i][j + 1]);

        if (j > 0 && r[j - 1] == l[j])
            for (int i = 0; i < n; i++)
                adder(upd[i][j], mans[i][j - 1]);
    }
    rows[++bottom] = l;
    mans = upd;
}
void remove() {
    cur++;
    if (cur > bottom)
        return;
    if (cur > mid) {
        mid = bottom;
        vector<vi> dp[2];
        int f = 0;
        reset(dp[f]);
        for (int i = 0; i < n; i++)
            dp[f][i][i] = 1;
        mans = dp[f];
        stor[top++] = dp[f];
        for (int k = bottom - 1; k >= cur; k--) {
            f ^= 1;
            reset(dp[f]);
            string r = rows[k + 1];
            string l = rows[k];
            for (int i = 0; i < n; i++) {
                if (l[i] == r[i])
                    for (int j = 0; j < n; j++)
                        adder(dp[f][i][j], dp[f ^ 1][i][j]);

                if (i < n - 1 && r[i + 1] == l[i])
                    for (int j = 0; j < n; j++)
                        adder(dp[f][i][j], dp[f ^ 1][i + 1][j]);

                if (i > 0 && r[i - 1] == l[i])
                    for (int j = 0; j < n; j++)
                        adder(dp[f][i][j], dp[f ^ 1][i - 1][j]);
            }
            stor[top++] = dp[f];
        }
    } else
        top--;
}
int path() {
    int c, d;
    cin >> c >> d;
    c--, d--;
    if (mid < cur)
        return mans[c][d];
    int ret = 0, res;
    for (int i = 0; i < n; i++) {
        res = (1LL * stor[top - 1][c][i] * mans[i][d]) % mod;
        adder(ret, res);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    cur = 0;
    bottom = mid = -1;
    for (int i = 0; i < q; i++) {
        string type;
        cin >> type;
        if (type[0] == 'a') {
            add();
        } else if (type[0] == 'r') {
            remove();
        } else if (type[0] == 'p') {
            cout << path() << '\n';
        }
    }
}
