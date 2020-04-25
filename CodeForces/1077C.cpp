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
    int n;
    cin >> n;
    multiset<int> s;
    vector<int> arr(n);
    ll sum = 0;
    for (int& a : arr) cin >> a, sum += a;
    int mx1 = max_element(arr.begin(), arr.end()) - arr.begin();
    int tmp = arr[mx1];
    arr[mx1] = -1;
    int mx2 = max_element(arr.begin(), arr.end()) - arr.begin();
    arr[mx1] = tmp;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        sum -= arr[i];
        if (i == mx1 && sum == 2 * arr[mx2]) {
            ans.pb(i + 1);
        } else if (i != mx1 && sum == 2 * arr[mx1]) {
            ans.pb(i + 1);
        }
        sum += arr[i];
    }
    cout << ans.size() << endl;
    for (int i : ans) cout << i << " ";
    cout << endl;
}