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
void solve(int test) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    if (n == 1) {
        puts("First");
        return;
    }
    int c1 = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] == 1) {
            c1 ^= 1;
        } else if (!c1) {
            c1 ^= 1;
        }
    }
    puts(c1 ? "First" : "Second");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
