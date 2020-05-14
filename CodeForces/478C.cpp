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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    ll ans = a[0] + a[1] + a[2];
    ans = min(ans / 3, ans - a[2]);
    cout << ans << '\n';
}
