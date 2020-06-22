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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    cout << (6 * n - 1) * k << '\n';
    for (int i = 0; i < n; i++) {
        cout << (6 * i + 1) * k << ' ';
        cout << (6 * i + 2) * k << ' ';
        cout << (6 * i + 3) * k << ' ';
        cout << (6 * i + 5) * k << '\n';
    }
}
