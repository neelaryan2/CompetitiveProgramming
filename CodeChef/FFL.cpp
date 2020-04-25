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
    int n, s;
    cin >> n >> s;
    s = 100 - s;
    vector<int> p(n), t(n);
    for (int& e : p) cin >> e;
    int m1 = s + 1, m2 = s + 1;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        if (t[i]) {
            m1 = min(m1, p[i]);
        } else {
            m2 = min(m2, p[i]);
        }
    }
    if (m1 + m2 <= s)
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