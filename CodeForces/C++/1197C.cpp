#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int& a : arr) cin >> a;
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1] - arr[i];
    }
    arr.pop_back();
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0; i < n - k; i++)
        ans += arr[i];
    if (k == n) ans = 0;
    cout << ans << endl;
}