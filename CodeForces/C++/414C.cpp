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
vector<int> temp;
void sex(vector<int>& arr, vector<ll>& ans, int l, int r, int d = 0) {
    if (r <= l + 1) return;
    int m = (r + l) / 2;
    sex(arr, ans, l, m, d + 1);
    sex(arr, ans, m, r, d + 1);
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            ans[d] += m - i;
        }
    }
    while (i < m)
        temp[k++] = arr[i++];
    while (j < r)
        temp[k++] = arr[j++];
    for (i = l; i < r; i++)
        arr[i] = temp[i];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    temp.resize(1 << n);
    vector<int> a1(1 << n);
    for (int& e : a1) cin >> e;
    vector<int> a2 = a1;
    reverse(all(a2));
    vector<ll> ans1(n + 1, 0), ans2(n + 1, 0);
    vector<int> flag(n + 1, 1);
    sex(a1, ans1, 0, 1 << n);
    sex(a2, ans2, 0, 1 << n);
    trace(ans1, ans2);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        for (int j = n - q; j <= n; j++)
            flag[j] ^= 1;
        ll ans = 0;
        for (int j = 0; j <= n; j++) {
            int f = flag[j];
            ans += f * ans1[j] + (1 - f) * ans2[j];
        }
        cout << ans << '\n';
    }
}
