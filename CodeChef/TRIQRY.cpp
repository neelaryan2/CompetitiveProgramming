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
bool cmp(ppi& a, ppi& b) {
    return a.fi.se - a.fi.fi < b.fi.se - b.fi.fi;
}
const int N = 1e6 + 10;
vector<int> B1, B2;
void add(vector<int>& BIT, int i, int x) {
    int t = BIT.size();
    for (; i < t; i += i & (-i)) 
    	BIT[i] += x;
}
int get(vector<int>& BIT, int i) {
    int sum = 0;
    for (; i > 0; i -= i & (-i)) 
    	sum += BIT[i];
    return sum;
}
void solve() {
    B1.assign(N, 0);
    B2.assign(2 * N, 0);
    int n, q;
    cin >> n >> q;
    vector<pii> pnts(n);
    for (pii& p : pnts)
        cin >> p.se >> p.fi;
    vector<ppi> que(q);
    vector<int> ans(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        que[i] = {{l, r}, i};
    }
    sort(all(que), cmp);
    sort(all(pnts));
    int ind = 0;
    for (ppi p : que) {
        int l = p.fi.fi;
        int r = p.fi.se;
        int up = (r - l) / 2;
        while (ind < n && pnts[ind].fi <= up) {
            int x = pnts[ind].se;
            int y = pnts[ind].fi;
            if (x >= y) {
                add(B1, x - y + 1, 1);
                add(B2, x + y, 1);
            }
            ind++;
        }
        ans[p.se] = get(B2, r) - get(B1, l);
    }
    for (int i : ans) cout << i << ' ';
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}