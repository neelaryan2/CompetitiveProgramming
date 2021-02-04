#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl '\n'
const ll inf = 3e9 + 5;
ll n, k;
vector<ll> arr;
bool check(int t) {
    ll m = 0;
    for (int i = n / 2; i < n; i++) {
        m += t - arr[i];
        if (m > k) return false;
    }
    return (m <= k);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    arr.resize(n);
    for (ll& a : arr) cin >> a;
    sort(arr.begin(), arr.end());
    ll lo = arr[n / 2], hi = inf, mid;
    while (lo < hi - 1) {
        mid = lo + (hi - lo) / 2;
        if (check(mid))
            lo = mid;
        else
            hi = mid;
    }
    cout << lo << endl;
}