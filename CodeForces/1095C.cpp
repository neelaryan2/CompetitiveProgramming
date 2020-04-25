#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, t;
    cin >> n >> k;
    vector<int> bin;
    for (; n; n >>= 1)
        bin.pb(n % 2), k -= n % 2;
    int ind = bin.size() - 1;
    while (k > 0 && ind > 0) {
        t = min(bin[ind], k);
        bin[ind] -= t;
        k -= t;
        ind--;
        bin[ind] += 2 * t;
    }
    if (k != 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<int> ans;
    for (int i = 0; i < bin.size(); i++) {
        while (bin[i]--)
            ans.pb(1 << i);
    }
    for (int i : ans) cout << i << " ";
    cout << endl;
}