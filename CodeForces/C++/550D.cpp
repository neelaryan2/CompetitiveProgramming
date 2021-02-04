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
int k;
void get_new(int p, int& cnt) {
    for (int i = 0; i < k / 2; i++) {
        cout << p << ' ' << cnt + (2 * i) << '\n';
        cout << p << ' ' << cnt + (2 * i + 1) << '\n';
    }
    cout << cnt + k - 1 << ' ' << cnt + k << '\n';
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < i; j++) {
            if (j == i - 1 && (i & 1)) continue;
            cout << cnt + j << ' ' << cnt + i << '\n';
        }
    }
    cnt += k + 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k;
    if (k % 2 == 0) {
        cout << "NO\n";
        return 0;
    }
    if (k == 1) {
        cout << "YES\n2 1\n1 2\n";
        return 0;
    }
    cout << "YES" << '\n';
    int cnt = 2;
    int t = (k + 1) * (k + 1);
    cout << t << ' ' << (t * k) / 2 << '\n';
    for (int i = 2; i < k + 2; i++) {
        cout << 1 << ' ' << cnt << '\n';
        cnt++;
        get_new(cnt - 1, cnt);
    }
}
