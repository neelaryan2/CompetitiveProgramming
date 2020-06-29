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
    if (n < 4) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if (n & 1) {
        cout << "5 - 3 = 2\n";
        cout << "2 + 1 = 3\n";
        cout << "2 * 4 = 8\n";
        cout << "8 * 3 = 24\n";
        for (int i = 6; i <= n; i += 2) {
            cout << i + 1 << " - " << i << " = 1\n";
            cout << "24 * 1 = 24\n";
        }
    } else {
        cout << "1 * 2 = 2\n";
        cout << "2 * 3 = 6\n";
        cout << "6 * 4 = 24\n";
        for (int i = 5; i <= n; i += 2) {
            cout << i + 1 << " - " << i << " = 1\n";
            cout << "24 * 1 = 24\n";
        }
    }
}
