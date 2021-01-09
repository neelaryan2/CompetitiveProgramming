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

bool is_prime(int n) {
    if (n % 2 == 0) 
        return (n == 2);
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) 
            return false;
    return true;
}

void solve(int test) {
    int n;
    cin >> n;
    if (is_prime(n))
        cout << 1;
    else if (n % 2 == 0)
        cout << 2;
    else if (is_prime(n - 2))
        cout << 2;
    else
        cout << 3;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
