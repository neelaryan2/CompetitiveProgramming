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

void add(vector<ll>& B, int i, ll x) {
    for (; i < B.size(); i += i & (-i))
        B[i] += x;
}
ll get(vector<ll>& B, int i) {
    ll sum = 0;
    for (; i > 0; i -= i & (-i))
        sum += B[i];
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<int> b(a);
    sort(all(b));
    map<int, int> comp;
    b.resize(distance(b.begin(), unique(all(b))));
    for (int i = 0; i < b.size(); i++)
        comp[b[i]] = i + 1;
    for (int& e : a) e = comp[e];
    vector<ll> inv(n), B1(n + 10), B2(n + 10);
    for (int i = 0; i < n; i++) {
        int e = a[i];
        inv[i] = get(B1, n + 9) - get(B1, e);
        add(B1, e, 1);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int e = a[i];
        ans += get(B2, n + 9) - get(B2, e);
        add(B2, e, inv[i]);
    }
    cout << ans << '\n';
}
