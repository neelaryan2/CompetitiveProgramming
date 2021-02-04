#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;

int main() {
        int n, b[200000];
        ll i, a[200000], ans = 0;
        cin >> n;
        for (i = 0; i < n; i++) {
                cin >> a[i];
                a[i] *= (i + 1) * (n - i);
        }
        for (i = 0; i < n; i++)
                cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        for (i = 0; i < n; i++)
                ans = (ans + (a[i] % MOD) * b[n - 1 - i] % MOD) % MOD;
        cout << ans;
        return 0;
}