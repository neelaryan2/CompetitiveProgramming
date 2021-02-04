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
map<int, int> cnt, have;
int zero = 0;
void add(int num, int x) {
    if (have[num] == cnt[num]) zero--;
    have[num] += x;
    if (have[num] == cnt[num]) zero++;
    assert(cnt.size() == have.size());
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, p;
    cin >> n >> m >> p;
    vector<vi> vec(p);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        a[i] = e;
        vec[i % p].pb(i);
        cnt[e] = 0;
        have[e] = 0;
    }
    for (int i = 0; i < m; i++) {
        int e;
        cin >> e;
        cnt[e]++;
        have[e] = 0;
    }
    for (pii p : cnt)
        if (p.se == 0)
            zero++;
    vector<int> ans;
    for (vi& v : vec) {
        int k = v.size();
        if (k < m) continue;
        for (int i = 0; i < m - 1; i++)
            add(a[v[i]], 1);
        for (int i = m - 1; i < k; i++) {
            add(a[v[i]], 1);
            if (zero == have.size())
                ans.pb(v[i - m + 1] + 1);
            add(a[v[i - m + 1]], -1);
        }
        for (int i = k - m + 1; i < k; i++)
            add(a[v[i]], -1);
    }
    sort(all(ans));
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << " ";
    cout << '\n';
}
