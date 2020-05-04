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
void pv(multiset<int> v) {
    vector<int> vec(all(v));
    cout << vec.size() - 1 << endl;
    for (int i = 1; i < vec.size(); i++) {
        cout << vec[i] - vec[i - 1] << ' ';
    }
    cout << '\n';
}
void solve() {
    int n;
    cin >> n;
    multiset<int> ans;
    int p = 0;
    while ((1 << (p + 1)) <= n + 1) p++;
    p--;
    for (int i = 0; i <= p; i++)
        ans.insert(1 << i);
    int diff = n + 1 - (1 << (p + 1));
    if (diff == 0) return pv(ans);
    ans.insert(diff);
    return pv(ans);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
