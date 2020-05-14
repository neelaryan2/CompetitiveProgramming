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
#define all(v) (v).begin(), (v).end()

bool solve() {
    int n, k;
    cin >> n >> k;
    bool f = false;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        if (e < k) continue;
        if (e == k) f = true;
        vec.pb(i);
    }
    if (!f) return false;
    if (n == 1) return true;
    for (int i = 1; i < vec.size(); i++)
        if (vec[i] - vec[i - 1] <= 2)
            return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) puts(solve() ? "yes" : "no");
}
