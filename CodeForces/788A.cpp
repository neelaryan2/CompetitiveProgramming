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
    vector<int> a(--n);
    int prv;
    cin >> prv;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        a[i] = abs(e - prv);
        if (i & 1) a[i] *= -1;
        prv = e;
    }
    ll mx1 = LLONG_MIN, mxcur1 = 0;
    ll mx2 = LLONG_MIN, mxcur2 = 0;
    for (int i = 0; i < n; i++) {
        mxcur1 = mxcur1 + a[i];
        mxcur2 = mxcur2 - a[i];
        mx1 = max(mx1, mxcur1);
        mx2 = max(mx2, mxcur2);
        mxcur1 = max(mxcur1, 0LL);
        mxcur2 = max(mxcur2, 0LL);
    }
    cout << max(mx1, mx2) << '\n';
}
