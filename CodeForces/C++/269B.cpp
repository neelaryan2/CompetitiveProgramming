/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<ld, int>;
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
    vector<pii> a(n);
    for (pii& p : a)
        cin >> p.se >> p.fi;
    sort(all(a));
    multiset<int> s;
    for (pii& p : a) {
        s.insert(p.se);
        auto it = s.upper_bound(p.se);
        if (it != s.end()) s.erase(it);
    }
    cout << n - s.size() << '\n';
}
