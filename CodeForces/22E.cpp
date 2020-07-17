#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> f(n), cnt(n, 0);
    vector<bool> vis(n, false);
    vector<int> head, tail;
    for (int& e : f) {
        cin >> e, e--;
        cnt[e]++;
    }
    for (int i = 0; i < n; i++) {
        if (cnt[i] || vis[i]) continue;
        int j = i;
        while (!vis[j]) {
            vis[j] = true;
            j = f[j];
        }
        head.eb(i + 1), tail.eb(j + 1);
    }
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        int j = i;
        while (!vis[j]) {
            vis[j] = true;
            j = f[j];
        }
        head.eb(i + 1), tail.eb(j + 1);
    }
    trace(head, tail);
    int m = head.size();
    if (m == 1 && head[0] == tail[0]) {
        cout << "0\n";
        return 0;
    }
    cout << m << '\n';
    for (int i = 0; i < m; i++)
        cout << tail[i] << ' ' << head[(i + 1) % m] << '\n';
}
