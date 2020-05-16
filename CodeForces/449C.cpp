/* Author - Neel Aryan (@neelaryan2) */
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
const int N = 1e5 + 10;
int least[N];
void sieve() {
    least[0] = 0;
    least[1] = 1;
    for (int i = 2; i < N; i++)
        least[i] = (i % 2) ? i : 2;
    for (int i = 3; i * i <= N; i += 2) {
        if (least[i] != i) continue;
        for (int j = i * i; j < N; j += i)
            if (least[j] == j)
                least[j] = i;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    int n;
    cin >> n;
    vector<bool> vis(n + 1, false);
    vis[0] = true;
    vector<pii> ans;
    vector<int> even;
    for (int p = n; p >= 3; p--) {
        if (least[p] != p) continue;
        vector<int> vec;
        for (int i = p; i <= n; i += p) {
            if (vis[i]) continue;
            vec.pb(i);
        }
        int k = vec.size();
        if (k <= 1)
            continue;
        if (k & 1) {
            even.pb(vec[1]);
            vis[vec[1]] = true;
            ans.pb(mp(vec[0], vec[2]));
            vis[vec[0]] = vis[vec[2]] = true;
            for (int i = 3; i < vec.size(); i += 2) {
                ans.pb(mp(vec[i], vec[i + 1]));
                vis[vec[i]] = vis[vec[i + 1]] = true;
            }
            continue;
        }
        for (int i = 0; i < vec.size(); i += 2) {
            ans.pb(mp(vec[i], vec[i + 1]));
            vis[vec[i]] = vis[vec[i + 1]] = true;
        }
    }
    trace(even);
    for (int i = 2; i <= n; i += 2)
        if (!vis[i]) even.pb(i);
    if (even.size() & 1) even.pop_back();
    for (int i = 0; i < even.size(); i += 2) {
        ans.pb(mp(even[i], even[i + 1]));
        vis[even[i]] = vis[even[i + 1]] = true;
    }
    cout << ans.size() << '\n';
    for (pii p : ans)
        cout << p.fi << ' ' << p.se << '\n';
}
