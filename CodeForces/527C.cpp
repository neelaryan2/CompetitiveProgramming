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
    int w, h, n;
    cin >> w >> h >> n;
    set<int> hh({0, h});
    set<int> ww({0, w});
    multiset<int> hv({h}), wv({w});
    for (int i = 0; i < n; i++) {
        string t;
        int x;
        cin >> t >> x;
        trace(hv, wv);
        if (t == "H") {
            auto it1 = hh.lb(x);
            auto it2 = it1--;
            hv.erase(hv.find(*it2 - *it1));
            hv.insert(*it2 - x);
            hv.insert(x - *it1);
            hh.insert(x);
        }
        if (t == "V") {
            auto it1 = ww.lb(x);
            auto it2 = it1--;
            wv.erase(wv.find(*it2 - *it1));
            wv.insert(*it2 - x);
            wv.insert(x - *it1);
            ww.insert(x);
        }
        int mxh = *prev(hv.end());
        int mxw = *prev(wv.end());
        cout << 1LL * mxh * mxw << '\n';
    }
}
