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
int n, m, p, nm;
vector<char> g;
vector<bool> vis;
vector<int> s, cnt;
vector<queue<int>> ex;
queue<int> q;
bool isEmpty(int v) {
    if (v < 0) return false;
    int i = v / m, j = v % m;
    if (i < 0 || i >= n) return false;
    if (j < 0 || j >= m) return false;
    return (g[v] == '.');
}
int dist(int u, int v) {
    int x1 = u / m, y1 = u % m;
    int x2 = v / m, y2 = v % m;
    return abs(x1 - x2) + abs(y1 - y2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> p;
    nm = n * m;
    g.resize(nm);
    s.resize(p);
    cnt.resize(p);
    ex.resize(p);
    for (int& e : s) cin >> e;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int v = i * m + j;
            char c;
            cin >> c;
            g[v] = c;
            if (c != '.' && c != '#') {
                int pl = c - '1';
                cnt[pl]++;
                ex[pl].push(v);
            }
        }
    }
    bool found = true;
    while (found) {
        found = false;
        for (int cur = 0; cur < p; cur++) {
            int dis = 0;
            while (dis != s[cur] && !ex[cur].empty()) {
                queue<int> tmp;
                while (!ex[cur].empty()) {
                    int u = ex[cur].front();
                    ex[cur].pop();
                    for (int mul : {-m, -1, m, 1}) {
                        int to = u + mul;
                        if (to / m != u / m && to % m != u % m) continue;
                        if (!isEmpty(to)) continue;
                        g[to] = cur + '1';
                        cnt[cur]++;
                        found = true;
                        tmp.push(to);
                    }
                }
                ex[cur] = tmp;
                dis++;
            }
        }
    }
    for (int i : cnt) cout << i << " ";
    cout << endl;
}