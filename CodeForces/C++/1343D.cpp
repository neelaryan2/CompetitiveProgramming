#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const ll N = 1e18;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    const int K = 2 * k + 5;
    vector<ll> cntmn(K, 0), sums(K, 0), cntmx(K, 0);
    for (int& e : arr) cin >> e;
    for (int i = 0; i < n / 2; i++) {
        int a1 = arr[i], a2 = arr[n - i - 1];
        cntmn[min(a1, a2)]++;
        cntmx[max(a1, a2)]++;
        sums[a1 + a2]++;
    }
    for (int i = 1; i < K; i++) {
        cntmn[i] += cntmn[i - 1];
        cntmx[i] += cntmx[i - 1];
    }
    ll ans = N;
    for (int s = 1; s < K; s++) {
        ll two = cntmn.back() - cntmn[s - 1];
        two += (s <= k) ? 0 : cntmx[s - k - 1];
        ll one = n / 2 - two - sums[s];
        ll res = 2LL * two + one;
        ans = min(res, ans);
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}