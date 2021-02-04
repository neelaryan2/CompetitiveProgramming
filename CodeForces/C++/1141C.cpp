#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int inf = INT_MAX;

const int N = 5e5 + 2;
vector<int> cnt1(N, 0), cnt2(N, 0);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, mn = 0;
    cin >> n;
    vector<ll> q(n, 0);
    for (int i = 1; i < n; i++) {
        cin >> q[i];
        q[i] += q[i - 1];
        mn = min(mn, q[i]);
    }
    vector<bool> vis(n, false);
    for (ll& a : q) {
        a -= mn - 1;
        if (a < 1 || a > n) {
            cout << -1 << endl;
            return 0;
        }
        vis[a - 1] = true;
    }
    bool f = true;
    for (bool b : vis) f = f && b;
    if (!f) {
        cout << -1 << endl;
        return 0;
    }
    for (ll i : q) cout << i << " ";
    cout << endl;
}