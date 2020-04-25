#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int inf = INT_MAX;
pii get() {
    string s;
    cin >> s;
    int sum = 0, mn = inf;
    for (char c : s) {
        if (c == '(') sum++;
        if (c == ')') sum--;
        mn = min(mn, sum);
    }
    return mp(mn, sum);
}
const int N = 5e5 + 2;
vector<int> cnt1(N, 0), cnt2(N, 0);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    while (n--) {
        pii p = get();
        if (p.fi < 0) {
            if (p.se == p.fi)
                cnt2[-p.fi]++;
        } else
            cnt1[p.se]++;
    }
    ll ans = (cnt1[0] + cnt2[0]) / 2;
    for (int i = 1; i < N; i++)
        ans += min(cnt1[i], cnt2[i]);
    cout << ans << endl;
}