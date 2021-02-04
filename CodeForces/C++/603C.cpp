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
int n, k;
int state(int x) {
    if (x == 0) return 0;
    if (!(k & 1)) {
        if (x <= 2) return x;
        return !(x & 1);
    }
    if (x <= 3) return (x & 1);
    if (x & 1) return 0;
    int c1 = state(x - 1);
    int c2 = state(x / 2);
    if (c1 != 0 && c2 != 0) return 0;
    if (c1 != 1 && c2 != 1) return 1;
    return 2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    int ans = 0;
    for (int i = 0, e; i < n; i++) {
        cin >> e;
        ans ^= state(e);
    }
    puts(ans ? "Kevin" : "Nicky");
}
