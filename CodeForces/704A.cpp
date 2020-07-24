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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<pii> glob;
    vector<int> pointers(n, 0), cnt(n, 0);
    int gpoint = 0, unread = 0;
    while (q--) {
        int typ, y;
        cin >> typ >> y;
        y--;
        if (typ == 1) {
            int c = cnt[y]++;
            glob.eb(y, c);
            unread++;
        }
        if (typ == 2) {
            int delta = cnt[y] - pointers[y];
            unread -= delta;
            pointers[y] += delta;
        }
        if (typ == 3) {
            while (gpoint <= y) {
                pii p = glob[gpoint++];
                int x = p.fi, c = p.se;
                if (pointers[x] <= c)
                    pointers[x]++, unread--;
            }
        }
        cout << unread << '\n';
    }
}
