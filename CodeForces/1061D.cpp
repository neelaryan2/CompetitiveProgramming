#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

const int kMod = 1e9 + 7;
struct ModInt {
    long long n;
    ModInt(long long n = 0) : n(n % kMod) {}
    ModInt operator+(const ModInt& oth) { return n + oth.n; }
    ModInt operator-(const ModInt& oth) { return n - oth.n; }
    ModInt operator*(const ModInt& oth) { return n * oth.n; }
    long long get() { return n < 0 ? n + kMod : n; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, x, y;
    cin >> n >> x >> y;
    ll up = x / y;
    vector<pii> seg(n);
    for (pii& p : seg)
        cin >> p.fi >> p.se;
    sort(all(seg));
    multiset<ll> s;
    ModInt ans = 0;
    for (pii p : seg) {
        auto it = s.lower_bound(p.fi);
        if (!s.empty() && it != s.begin()) it--;
        if (s.empty() || *it < p.fi - up || *it >= p.fi) {
            ans = ans + x + (p.se - p.fi) * y;
        } else {
            ans = ans + (p.se - *it) * y;
            s.erase(it);
        }
        s.insert(p.se);
    }
    cout << ans.get() << endl;
}