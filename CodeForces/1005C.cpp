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
    vector<int> arr(n), has(n, false);
    map<int, int> cnt;
    for (int& a : arr) {
        cin >> a;
        cnt[a]++;
    }
    for (int i = 0; i < n; i++) {
        auto ti = cnt.find(arr[i]);
        ti->second--;
        for (int j = 1, pw = 2; j <= 30; j++, pw <<= 1) {
            int curr = pw - arr[i];
            auto it = cnt.find(curr);
            if (it != cnt.end() && it->second > 0) {
                has[i] = true;
                break;
            }
        }
        ti->second++;
    }
    int ans = accumulate(has.begin(), has.end(), 0);
    cout << n - ans << endl;
}