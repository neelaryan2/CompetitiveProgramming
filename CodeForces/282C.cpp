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
    string a, b;
    cin >> a >> b;
    if (a.size() != b.size()) {
        puts("NO");
        return 0;
    }
    int f1 = 0, f2 = 0;
    for (char c : a)
        if (c == '1') f1 = 1;
    for (char c : b)
        if (c == '1') f2 = 1;
    puts((f1 ^ f2) ? "NO" : "YES");
}
