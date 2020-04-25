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

vector<ll> vec(1, 0);
vector<ll> p(1, 0);
bool check(int id) {
    ll sum = p[id] + vec.back();
    ld avg = ((ld)sum) / (id + 1);
    return (vec[id] > avg);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q = 1;
    cin >> q;
    ld ans = -1;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int v;
            cin >> v;
            vec.pb(v);
            p.pb(p.back() + v);
            int lo = 0, hi = vec.size(), mid;
            while (lo < hi - 1) {
                mid = lo + (hi - lo) / 2;
                if (check(mid))
                    hi = mid;
                else
                    lo = mid;
            }
            ll sum = p[lo] + vec.back();
            ld avg = ((ld)sum) / (lo + 1);
            ld curr = vec.back() - avg;
            ans = max(ans, curr);
        } else {
            cout << fixed << setprecision(10) << ans << "\n";
        }
    }
}