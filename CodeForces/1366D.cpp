/* Author - Neel Aryan (@neelaryan2) */
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

const int N = 1e7 + 5;
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
    vector<int> a(n);
    vector<int> d1, d2;
    for (int& e : a) {
        cin >> e;
        int c = e, cur = 1;
        while (c > 1) {
            int p = least[c];
            while (c % p == 0) c /= p, cur *= p;
            break;
        }
        if (c == 1) cur = -1;
        d1.eb(cur);
        if (cur != -1) cur = e / cur;
        d2.eb(cur);
    }
    for (int e : d1) cout << e << ' ';
    cout << '\n';
    for (int e : d2) cout << e << ' ';
    cout << '\n';
}
