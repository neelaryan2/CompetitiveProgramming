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
    int n, m;
    cin >> n >> m;
    if (m == 2 && n == 2) {
        puts("YES");
        return;
    }
    if (m == 1 || n == 1) {
        puts("YES");
        return;
    }
    puts("NO");
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
