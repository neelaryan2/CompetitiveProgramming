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
const int N = 2e5 + 50;
int least[N], cnt[N];
pii minp[N];
void sieve() {
    least[0] = 0;
    least[1] = 1;
    for (int i = 0; i < N; i++) {
        minp[i] = {N, N};
        cnt[i] = 0;
    }
    for (int i = 2; i < N; i++)
        least[i] = (i % 2) ? i : 2;
    for (int i = 3; i <= N / i; i += 2) {
        if (least[i] != i) continue;
        for (int j = i * i; j < N; j += i)
            if (least[j] == j)
                least[j] = i;
    }
}
void update(int prime, int cnt) {
    pii& p = minp[prime];
    if (cnt < p.fi) {
        p.se = p.fi;
        p.fi = cnt;
        return;
    }
    if (cnt < p.se) {
        p.se = cnt;
        return;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        while (e > 1) {
            int p = least[e], cnts = 0;
            while (e % p == 0) e /= p, cnts++;
            update(p, cnts), cnt[p]++;
        }
    }
    ll ans = 1;
    for (int i = 2; i < N; i++) {
        if (cnt[i] <= n - 2) continue;
        pii& p = minp[i];
        if (cnt[i] == n - 1) {
            while (p.fi--) ans *= 1LL * i;
        } else {
            while (p.se--) ans *= 1LL * i;
        }
    }
    cout << ans << '\n';
}
