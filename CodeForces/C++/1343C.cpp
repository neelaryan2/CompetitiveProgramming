#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).rbegin(), (v).rend()

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& e : arr) cin >> e;
    ll last = arr[0];
    ll sum = arr[0];
    for (int i = 1; i < n; i++) {
        if (last * arr[i] > 0) {
            if (arr[i] > last) {
                sum += arr[i] - last;
                last = arr[i];
            }
        } else {
            sum += arr[i];
            last = arr[i];
        }
    }
    cout << sum << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}