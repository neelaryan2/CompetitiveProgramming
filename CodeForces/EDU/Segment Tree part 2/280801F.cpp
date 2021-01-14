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

const int NO_OP = INT_MIN;

struct node {
    int sum, mx, lazy;
    int tl, tr;
    node *vl, *vr;

    node(int tl_, int tr_) {
        sum = mx = 0;
        lazy = NO_OP;
        tl = tl_, tr = tr_;
        vl = NULL, vr = NULL;
    }

    void push() {
        if (tr <= tl) return;  // leaf
        int tm = (tl + tr) / 2;
        if (vl == NULL) {
            vl = new node(tl, tm);
            vr = new node(tm + 1, tr);
        }
        if (lazy == NO_OP) return;
        vl->lazy = lazy, vr->lazy = lazy;
        vl->sum = lazy * (tm - tl + 1);
        vl->mx = vl->sum;
        vr->sum = lazy * (tr - tm);
        vr->mx = vr->sum;
        lazy = NO_OP;
    }

    int query(int h) {
        if (mx <= h) return -1;
        if (tl == tr) return tl - 1;
        push();
        if (vl->mx > h)
            return vl->query(h);
        else
            return vr->query(h - vl->sum);
    }

    void update(int l, int r, int d) {
        if (l > tr || r < tl) return;
        if (l <= tl && tr <= r) {
            sum = d * (tr - tl + 1);
            mx = sum, lazy = d;
        } else {
            push();
            vl->update(l, r, d);
            vr->update(l, r, d);
            sum = vl->sum + vr->sum;
            mx = max(vl->mx, vl->sum + vr->mx);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    node segtree(1, n);

    string op;

    while (true) {
        cin >> op;
        if (op == "E")
            break;
        if (op == "Q") {
            int h;
            cin >> h;
            h = segtree.query(h);
            if (h == -1) h = n;
            cout << h << '\n';
        }
        if (op == "I") {
            int a, b, d;
            cin >> a >> b >> d;
            segtree.update(a, b, d);
        }
    }

    return 0;
}