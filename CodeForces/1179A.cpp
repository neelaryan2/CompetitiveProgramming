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
    int n, qq;
    cin >> n >> qq;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    deque<int> q(all(a));
    int mx = *max_element(all(a));
    vector<pii> ans;
    while (q.front() != mx) {
        int A = q.front();
        q.pop_front();
        int B = q.front();
        q.pop_front();
        ans.eb(A, B);
        q.push_front(max(A, B));
        q.push_back(min(A, B));
    }
    a.assign(all(q));
    for (int i = 0; i < qq; i++) {
        ll m;
        cin >> m;
        if (m <= ans.size()) {
            pii p = ans[m - 1];
            cout << p.fi << ' ' << p.se << '\n';
            continue;
        }
        m -= ans.size();
        m %= (n - 1);
        if (m == 0) m = n - 1;
        cout << mx << ' ' << a[m] << '\n';
    }
}
