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
const int N = 1e6 + 100;
vector<int> cnt(N, 0);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        cnt[e]++;
    }
    int c = 0;
    for (int i = 0; i < N; i++) {
        cnt[i] += c;
        c = cnt[i] / 2;
        cnt[i] &= 1;
    }
    c = accumulate(all(cnt), 0);
    cout << c << '\n';
}
