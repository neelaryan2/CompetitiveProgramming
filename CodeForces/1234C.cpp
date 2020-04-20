#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<bool, bool>;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl '\n'
const ll inf = 3e9 + 5;
void solve() {
    int n;
    cin >> n;
    vector<bool> pip[2];
    for (int i : {0, 1}) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            pip[i].pb(c > '2');
        }
    }
    int i = 0, j = 0;
    for (; j < n; j++) {
        if (pip[i][j]) {
            if (pip[1 - i][j])
                i = 1 - i;
            else
                break;
        }
    }
    puts((i == 1 && j == n) ? "YES" : "NO");
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
}