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
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> v1, v2;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t <= c / 2) {
            int ind = upper_bound(all(v1), t) - v1.begin();
            if (ind == v1.size()) v1.emplace_back();
            v1[ind] = t;
            cout << ind + 1 << endl;
        } else {
            int ind = upper_bound(all(v2), -t) - v2.begin();
            if (ind == v2.size()) v2.emplace_back();
            v2[ind] = -t;
            cout << n - ind << endl;
        }
        if (v1.size() + v2.size() == n) return 0;
    }
}