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
    ll ans = 0;
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<int> b(n);
    vector<bool> sex(n, false);
    for (ll& e : a) cin >> e;
    for (int& e : b) cin >> e;
    for (int i = 0; i < n; i++) {
        bool take = false;
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                take = true;
                break;
            }
        }
        if (!take) continue;
        for (int j = 0; j < n; j++) {
            if ((a[i] & a[j]) == a[j])
                sex[j] = true;
        }
    }
    for (int i = 0; i < n; i++)
        if (sex[i]) ans += b[i];
    cout << ans << '\n';
}
