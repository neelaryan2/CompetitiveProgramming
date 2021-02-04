#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<ld> p(n);
    for (ld& e : p) cin >> e;
    sort(rall(p));
    ld ans = 0, pr = 1, sum = 0;
    for (ld& e : p) {
        if (e == 1) {
            ans = 1;
            break;
        }
        pr = pr * (1 - e);
        sum += e / (1 - e);
        ans = max(ans, pr * sum);
    }
    cout << fixed << setprecision(12) << ans << '\n';
}
