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
const int N = 1e5 + 5;
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
int inv(int e, int m) {
    int p = m - 2, r = 1;
    while (p) {
        if (p & 1) r = (1LL * r * e) % m;
        e = (1LL * e * e) % m;
        p >>= 1;
    }
    return r;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    int n;
    cin >> n;
    if (n == 1) {
        cout << "YES\n1\n";
        return 0;
    }
    if (n == 4) {
        cout << "YES\n1\n3\n2\n4\n";
        return 0;
    }
    if (least[n] != n) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n1\n";
    for (int i = 2; i < n; i++) {
        int ans = (1LL * i * inv(i - 1, n)) % n;
        cout << ans << '\n';
    }
    cout << n << '\n';
}
