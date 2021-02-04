#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 1; i < n; i++)
        arr[i] += arr[i - 1];
    if (arr[n - 1] % 3) {
        cout << 0 << endl;
        return 0;
    }
    ll sum = arr[n - 1] / 3;
    ll cnt = 0, ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == 2 * sum)
            ans += cnt;
        if (arr[i] == sum)
            cnt++;
    }
    cout << ans << endl;
}