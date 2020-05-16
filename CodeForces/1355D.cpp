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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, s;
    cin >> n >> s;
    if (s < 2 * n) {
        cout << "NO\n";
        return 0;
    }
    vector<int> ans(n, 1);
    ans[n - 1] += s - n;
    cout << "YES\n";
    for (int i : ans) cout << i << " ";
    cout << '\n';
    cout << n << '\n';
}
