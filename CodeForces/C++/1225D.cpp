#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second
#define endl '\n'
const int N = 1e5 + 5;
int least[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
    int n, k;
    cin >> n >> k;
    vector<vector<pii>> arr(n);
    for (auto& v : arr) {
        int a;
        cin >> a;
        while (a > 1) {
            int p = least[a], cnt = 0;
            while (a % p == 0) a /= p, cnt++;
            if (cnt % k != 0)
                v.push_back({p, cnt % k});
        }
    }
    map<vector<pii>, int> cnt;
    ll ans = 0;
    for (auto& v : arr) {
        vector<pii> tmp = v;
        for (pii& p : tmp) p.se = (k - p.se) % k;
        auto it = cnt.find(tmp);
        if (it != cnt.end())
            ans += it->se;
        cnt[v]++;
    }
    cout << ans << endl;
}