#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ppi = pair<int, pii>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const int mxN = 5005;
vector<int> BIT(2 * mxN + 2, 0);
void add(int i, int x) {
    for (; i < BIT.size(); i += i & (-i)) BIT[i] += x;
}
int get(int i) {
    int sum = 0;
    for (; i > 0; i -= i & (-i)) sum += BIT[i];
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, ans = 0;
    cin >> n;
    vector<ppi> vert, hort;
    vector<pii> vec;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += mxN, x2 += mxN;
        y1 += mxN, y2 += mxN;
        if (x1 == x2) {
            if (y1 > y2) swap(y1, y2);
            vert.pb({x1, {y1, y2}});
        } else {
            if (x1 > x2) swap(x1, x2);
            hort.pb({y1, {x1, x2}});
        }
    }
    sort(all(hort));
    sort(all(vert), [&](ppi a, ppi b) {
        return a.se.fi < b.se.fi;
    });
    for (int i = 0; i < hort.size(); i++) {
        ppi p = hort[i];
        for (int j = 0; j < vert.size(); j++) {
            ppi q = vert[j];
            if (q.se.se < p.fi || q.se.fi > p.fi) continue;
            if (p.se.se < q.fi || p.se.fi > q.fi) continue;
            vec.pb({q.se.fi, q.fi});
            add(q.fi, 1);
        }
        for (int j = i - 1; j >= 0; j--) {
            ppi q = hort[j];
            while (!vec.empty() && vec.back().fi > q.fi) {
                add(vec.back().se, -1);
                vec.pop_back();
            }
            int lef = max(q.se.fi, p.se.fi);
            int righ = min(q.se.se, p.se.se);
            if (lef >= righ) continue;
            ll res = get(righ) - get(lef - 1);
            ans += (res * (res - 1)) / 2;
        }
        while (!vec.empty()) {
            add(vec.back().se, -1);
            vec.pop_back();
        }
    }
    cout << ans << '\n';
}
