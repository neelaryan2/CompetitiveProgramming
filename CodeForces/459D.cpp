#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> BIT;
void add(int i, int x) {
    for (; i < BIT.size(); i += i & (-i)) BIT[i] += x;
}
int get(int i) {
    int sum = 0;
    for (; i > 0; i -= i & (-i)) sum += BIT[i];
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    BIT.resize(n + 2, 0);
    map<int, int> cnt;
    vector<int> a1(n), a2(n), arr(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
        arr[i] = a;
        a1[i] = cnt[a];
    }
    for (int i = 0; i < n; i++) {
        a2[i] = cnt[arr[i]] - a1[i] + 1;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += get(n) - get(a2[i]);
        add(a1[i], 1);
    }
    cout << ans << endl;
}