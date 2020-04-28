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
    string s;
    cin >> s;
    int n = s.size();
    if (n % 2) {
        char c = s[0];
        for (char t : s)
            if (t != c) {
                cout << "NO\n";
                return;
            }
        cout << "YES\n";
        return;
    }
    vector<string> vec(2);
    for (int i = 0; i < n; i++) {
        vec[i % 2].pb(s[i]);
    }
    for (int i : {0, 1}) {
        char c = vec[i][0];
        for (char t : vec[i])
            if (t != c) {
                cout << "NO\n";
                return;
            }
    }
    cout << "YES\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}