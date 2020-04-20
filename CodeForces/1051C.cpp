#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    const int m = 101;
    vector<vector<int>> ind(m);
    vector<char> ans(n, 'A');
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ind[a].pb(i);
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (ind[i].size() == 1)
            cnt++;
    }
    int hf = cnt / 2;
    for (int i = 0; i < m; i++) {
        if (hf == 0) break;
        if (ind[i].size() == 1) {
            ans[ind[i][0]] = 'B';
            ind[i].clear();
            hf--;
        }
    }
    if (cnt % 2 != 0) {
        bool done = false;
        for (int i = 0; i < m; i++) {
            if (ind[i].size() > 2) {
                ans[ind[i][0]] = 'B';
                done = true;
                break;
            }
        }
        if (!done) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for (char c : ans) cout << c;
    cout << endl;
}