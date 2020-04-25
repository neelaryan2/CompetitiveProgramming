#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define fi first
#define se second
#define pii pair<pair<int, int>, int>
map<int, int> cnt;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    int m;
    cin >> m;
    vector<pii> arr(m);
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        arr[i].fi.fi = cnt[a];
        arr[i].se = i + 1;
    }
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        arr[i].fi.se = cnt[a];
    }
    sort(arr.rbegin(), arr.rend());
    cout << arr[0].se << endl;
}