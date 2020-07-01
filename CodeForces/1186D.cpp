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
    vector<ld> a(n);
    vector<int> b(n);
    int sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = int(a[i]);
        if (a[i] < 0 && a[i] != b[i]) 
            b[i]--;
        sm -= b[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (sm && a[i] != b[i])
            b[i]++, sm--;
        sum += b[i];
        cout << b[i] << '\n';
    }
    assert(sum == 0);
}
