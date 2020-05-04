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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(i);
    vector<int> ans(n, 0);
    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        --l, --r, --x;
        for (auto it = s.lower_bound(l); it != s.end() && *it <= r;) {
            if (*it == x)
                it++;
            else {
                ans[*it] = x + 1;
                it = s.erase(it);
            }
        }
    }
    for (int i : ans) cout << i << " ";
    cout << '\n';
}
