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
int n, m;
vector<vi> g;
bool check(int x) {
    vector<bitset<1000>> b(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            b[i][j] = (g[i][j] >= x);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if ((b[i] & b[j]).count() >= 2)
                return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n);
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        g[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            vec.pb(g[i][j]);
        }
    }
    sort(all(vec));
    vec.resize(distance(vec.begin(), unique(all(vec))));
    int lo = 0, hi = vec.size(), mid;
    while (lo < hi - 1) {
        mid = lo + (hi - lo) / 2;
        if (check(vec[mid]))
            lo = mid;
        else
            hi = mid;
    }
    cout << vec[lo] << '\n';
}
