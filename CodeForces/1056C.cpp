/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    set<pii> s, pa;
    vector<int> po(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        int e;
        cin >> e;
        s.insert({-e, i});
        po[i] = e;
    }
    vector<int> g(2 * n, -1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (po[a] < po[b]) swap(a, b);
        g[a] = b;
        g[b] = a;
        pa.insert(mp(a, b));
    }
    int t;
    cin >> t;
    if (t == 1) {
        int ind = -1;
        for (int i = 0; i < n; i++) {
            if (!pa.empty()) {
                pii p = *pa.begin();
                pa.erase(pa.begin());
                s.erase(mp(-po[p.fi], p.fi));
                s.erase(mp(-po[p.se], p.se));
                g[p.se] = -1;
                g[p.fi] = -1;
                cout << p.fi + 1 << endl;
                cin >> ind;
                ind--;
            } else {
                pii p = *s.begin();
                s.erase(s.begin());
                cout << p.se + 1 << endl;
                cin >> ind;
                ind--;
                p = mp(-po[ind], ind);
                s.erase(p);
            }
        }
    } else {
        int ind = -1;
        for (int i = 0; i < n; i++) {
            cin >> ind;
            ind--;
            if (g[ind] != -1) {
                pii p = mp(ind, g[ind]);
                if (po[p.fi] < po[p.se]) swap(p.fi, p.se);
                pa.erase(p);
                s.erase(mp(-po[p.fi], p.fi));
                s.erase(mp(-po[p.se], p.se));
                cout << g[ind] + 1 << endl;
            } else {
                if (!pa.empty()) {
                    pii p = mp(-po[ind], ind);
                    s.erase(p);
                    p = *pa.begin();
                    pa.erase(pa.begin());
                    s.erase(mp(-po[p.fi], p.fi));
                    s.erase(mp(-po[p.se], p.se));
                    g[p.se] = -1;
                    g[p.fi] = -1;
                    cout << p.fi + 1 << endl;
                } else {
                    pii p = mp(-po[ind], ind);
                    s.erase(p);
                    p = *s.begin();
                    s.erase(s.begin());
                    cout << p.se + 1 << endl;
                }
            }
        }
    }
}
