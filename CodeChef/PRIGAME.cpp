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
#define rall(v) (v).rbegin(), (v).rend()

const int inf = 1e9 + 7;

vector<int> prime;
void sieve(int n) {
    prime.assign(n + 1, 1);
    prime[0] = prime[1] = 0;
    for (int p = 2; p * p <= n; p++) {
        if (!prime[p]) continue;
        for (int i = p * p; i <= n; i += p)
            prime[i] = 0;
    }
    for (int i = 1; i <= n; i++)
        prime[i] += prime[i - 1];
}
void solve(int test) {
    int x, y;
    cin >> x >> y;
    int cur = 1 + (prime[x] - 1) / y;
    cout << ((cur & 1) ? "Chef" : "Divyam");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve(1e6 + 7);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
        cout << '\n';
    }
}
