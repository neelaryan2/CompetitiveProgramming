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
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;

struct child {
    ll v, d, p, id;
    friend ostream& operator<<(ostream& os, child const& a) {
        os << "(v:" << a.v << ", d:" << a.d;
        os << ", p:" << a.p << ", id:" << a.id;
        return os << ")";
    }
};
vector<child> ch;
void solve(int test) {
    int n;
    cin >> n;
    ch.resize(n);
    for (int i = n - 1; i >= 0; i--) {
        cin >> ch[i].v >> ch[i].d >> ch[i].p;
        ch[i].id = n - i;
    }
    vector<int> ans;
    while (!ch.empty()) {
        trace(ch);

        child c = ch.back();
        ch.pop_back();
        ans.eb(c.id);

        int k = ch.size();
        for (int i = 0; i < k; i++)
            ch[i].p -= max(0LL, c.v - (k - i - 1));

        trace(ch);
        while (true) {
            bool found = false;
            vector<ll> suf(k + 1, 0), vec;
            for (int i = 0; i < k; i++)
                if (ch[i].p < 0) {
                    suf[i] -= ch[i].d;
                    found = true;
                    vec.eb(i);
                }
            if (!found) break;

            for (int i = k - 1; i >= 0; i--)
                suf[i] += suf[i + 1];

            vector<child> new_ch;
            int ptr = 0;
            for (int i = 0; i < k; i++) {
                if (ptr < vec.size() && i == vec[ptr])
                    ptr++;
                else {
                    ch[i].p += suf[i];
                    new_ch.eb(ch[i]);
                }
            }
            swap(ch, new_ch);
            k = ch.size();
        }
    }
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}