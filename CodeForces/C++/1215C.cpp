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
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> v1, v2;
    vector<pii> ans;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        if (a[i] == 'a') v1.eb(i + 1);
        if (b[i] == 'a') v2.eb(i + 1);
    }
    if ((v2.size() - v1.size()) & 1) {
        cout << "-1\n";
        return 0;
    }
    if (v1.size() & 1) {
        int i = v1.back();
        v1.pop_back();
        int j = v2.back();
        v2.pop_back();
        ans.eb(i, i);
        ans.eb(i, j);
    }
    for (int i = 0; i < v1.size(); i += 2)
        ans.eb(v1[i], v1[i + 1]);
    for (int i = 0; i < v2.size(); i += 2)
        ans.eb(v2[i], v2[i + 1]);
    cout << ans.size() << '\n';
    for (pii p : ans)
        cout << p.fi << ' ' << p.se << '\n';
}
