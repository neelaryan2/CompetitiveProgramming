#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl '\n'
const int inf = INT_MAX;

ll solve() {
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    if (b * k >= n) return -1;
    n -= b * k + 1;
    return min(n / (a - b), k);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
}