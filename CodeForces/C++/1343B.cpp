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

void solve() {
    ll n;
    cin >> n;
    n /= 2;
    if (n & 1) {
        cout << "NO" << endl;
        return;
    }
    vector<int> a(2 * n);
    for (int i = 0; i < n; i++)
        a[i] = 2 * i + 2;
    for (int i = n; i < 2 * n; i++)
        a[i] = 2 * (i - n) + 1;
    a.back() += n;
    cout << "YES" << endl;
    for (int i : a) cout << i << " ";
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}