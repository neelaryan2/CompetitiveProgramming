#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, a; cin >> n >> k;
    long long ans = 0;
    multiset<int> s;
    vector<int> arr;
    for (int i = 0; i < n; i++)
        cin >> a, s.insert(a);
    arr.assign(s.begin(), s.end());
    for (int a : arr)
        ans += s.count(a + k);
    cout << ans << endl;
}
