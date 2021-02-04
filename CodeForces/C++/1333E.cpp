#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int cnt = n * n;
    if (n <= 2) {
        cout << -1 << endl;
        return 0;
    }
    vector<vi> g(n, vi(n));
    g[0][2] = cnt--;
    g[2][2] = cnt--;
    g[1][0] = cnt--;
    g[0][0] = cnt--;
    g[0][1] = cnt--;
    g[1][2] = cnt--;
    g[1][1] = cnt--;
    g[2][1] = cnt--;
    g[2][0] = cnt--;
    for (int j = 0; j < 3; j++) {
        if (j % 2 == 0) {
            for (int i = 3; i < n; i++)
                g[i][j] = cnt--;
        } else {
            for (int i = n - 1; i >= 3; i--)
                g[i][j] = cnt--;
        }
    }
    for (int j = 3; j < n; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < n; i++)
                g[i][j] = cnt--;
        } else {
            for (int i = n - 1; i >= 0; i--)
                g[i][j] = cnt--;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << g[i][j] << ' ';
        cout << endl;
    }
}