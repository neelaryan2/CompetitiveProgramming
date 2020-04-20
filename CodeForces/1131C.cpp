#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    deque<int> q;
    vector<int> arr(n);
    for (int& a : arr) cin >> a;
    sort(arr.rbegin(), arr.rend());
    for (int i = 0; i < n; i++) {
        if (i % 2)
            q.push_front(arr[i]);
        else
            q.push_back(arr[i]);
    }
    for (int a : q) cout << a << " ";
    cout << endl;
}