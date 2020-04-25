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
#define all(v) (v).rbegin(), (v).rend()

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vi> b(k);
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        b[i % k].pb(e);
    }
    for (int i = 0; i < k; i++) {
        sort(all(b[i]));
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = b[i % k].back();
        b[i % k].pop_back();
    }
    if (is_sorted(a.begin(),a.end()))
        cout << "yes\n";
    else
        cout << "no\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}