#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
vi arr;
long merge(int s, int m, int e) {
    long ans = 0; vi l, r; int i, j, st = s;
    for (i = s; i < m; i++) l.emplace_back(arr[i]);
    for (j = m; j < e; j++) r.emplace_back(arr[j]);
    m = l.size(); e = r.size();
    for (i = 0, j = 0; i < m && j < e;) {
        if (l[i] > r[j]) arr[st++] = r[j++], ans += m - i;
        else arr[st++] = l[i++];
    }
    while (i < m) arr[st++] = l[i++];
    while (j < e) arr[st++] = r[j++];
    return ans;
}
long mergesort(int s, int e) {
    if (s >= e - 1) return 0;
    int m = (s + e) / 2; long ans = 0;
    ans += mergesort(s, m);
    ans += mergesort(m, e);
    ans += merge(s, m, e);
    return ans;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        arr.assign(n, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << mergesort(0, n) << "\n";
    }
    return 0;
}
