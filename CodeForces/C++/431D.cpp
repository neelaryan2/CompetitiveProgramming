#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const int B = 63;
ll m, k;
ll C[B + 1][B + 1];
ll get(ll x) {
    ll ret = 0, on = 0;
    for (int i = B; i >= 0 && k >= on; i--) {
        if ((x >> i) & 1) {
            ret += C[i][k - on++];
        }
    }
    if (on == k) ret++;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(C, 0, sizeof(C));
    C[0][0] = 1;
    for (int i = 1; i <= B; i++) {
        for (int j = 0; j <= i; j++) {
            C[i][j] += C[i - 1][j];
            if (j) C[i][j] += C[i - 1][j - 1];
        }
    }
    cin >> m >> k;
    ll lo = 0, hi = 1e18 + 1, mid, res;
    while (lo < hi - 1) {
        mid = lo + (hi - lo) / 2;
        res = get(2 * mid) - get(mid);
        if (res >= m)
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << '\n';
}
