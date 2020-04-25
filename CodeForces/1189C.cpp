#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl '\n'
const int N = 1e5 + 5;
vector<vector<pii>> dp(N, vector<pii>(17, mp(-1, -1)));
vector<int> arr;
pii calc(int s, int l) {
    pii& p = dp[s][l];
    if (p.se != -1) return p;
    if (l == 0) {
        p.fi = arr[s];
        p.se = 0;
        return p;
    }
    int len = 1 << (l - 1);
    pii p1 = dp[s][l - 1];
    if (p1.se == -1) p1 = calc(s, l - 1);
    pii p2 = dp[s + len][l - 1];
    if (p2.se == -1) p2 = calc(s + len, l - 1);
    if (p1.fi + p2.fi >= 10)
        p.se = 1;
    else
        p.se = 0;
    p.se += p1.se + p2.se;
    p.fi = (p1.fi + p2.fi) % 10;
    return p;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    arr.resize(n);
    for (int& a : arr) cin >> a;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        r = log2(r - l + 1);
        cout << calc(l - 1, r).se << endl;
    }
}