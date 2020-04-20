#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = INT_MAX;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> s(n), c(n);
    for (int& a : s) cin >> a;
    for (int& a : c) cin >> a;
    int ans = inf;
    for (int j = 1; j < n-1; j++) {
        int c1 = inf, c2 = inf;
        for (int i = 0; i < j; i++) {
            if (s[i] < s[j])
                c1 = min(c1, c[i]);
        }
        for (int k = j + 1; k < n; k++) {
            if (s[k] > s[j])
                c2 = min(c2, c[k]);
        }
        if (c1 == inf || c2 == inf) continue;
        ans = min(ans, c[j] + c1 + c2);
    }
    cout << (ans == inf ? -1 : ans) << endl;
}