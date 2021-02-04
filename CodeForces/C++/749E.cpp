#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using ppi = pair<pii, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
int N = 5e5 + 10;

vector<ld> B1, B2;
void add(vector<ld>& B, int i, int x) {
    int n = B.size();
    for (; i < n; i += i & (-i))
        B[i] = B[i] + x;
}
ld sum(vector<ld>& B, int i) {
    ld sum = 0;
    for (; i > 0; i -= i & (-i))
        sum = sum + B[i];
    return sum;
}
void solve() {
    int n;
    cin >> n;
    B1.assign(n + 5, 0);
    B2.assign(n + 5, 0);
    vector<int> arr(n);
    for (int& e : arr) cin >> e;
    ld sum1 = 0, sum2 = 0, fin = 0;
    ld tot = (1LL * n * (n + 1)) / 2;
    for (int i = n - 1; i >= 0; i--) {
        int c = arr[i];
        sum1 += sum(B1, c);
        sum2 += sum(B2, c);
        fin += sum2;
        add(B1, c, 1);
        add(B2, c, n - i);
    }
    ld ans = sum1 - fin / tot + (tot - 1) / 12;
    cout << fixed << setprecision(30) << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}