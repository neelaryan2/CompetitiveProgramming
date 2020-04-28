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
    int n;
    cin >> n;
    int nn = n * n;
    vector<char> g(nn, '#');
    vector<int> to(nn);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            int v = i * n + j;
            int u = x * n + y;
            if (x < 0 || y < 0)
                to[v] = -1;
            else
                to[v] = u;
            if (v == u) {
                g[v] = 'X';
                q.push(v);
            }
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        int x = v / n, y = v % n;
        if (x > 0 && to[v - n] == to[v] && g[v - n] == '#') {
            q.push(v - n);
            g[v - n] = 'D';
        }
        if (y > 0 && to[v - 1] == to[v] && g[v - 1] == '#') {
            q.push(v - 1);
            g[v - 1] = 'R';
        }
        if (x < n - 1 && to[v + n] == to[v] && g[v + n] == '#') {
            q.push(v + n);
            g[v + n] = 'U';
        }
        if (y < n - 1 && to[v + 1] == to[v] && g[v + 1] == '#') {
            q.push(v + 1);
            g[v + 1] = 'L';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int v = i * n + j;
            if (g[v] != '#' || to[v] != -1)
                continue;
            if (j > 0 && to[v - 1] == -1) {
                g[v] = 'L';
                if (g[v - 1] == '#') g[v - 1] = 'R';
            } else if (i > 0 && to[v - n] == -1) {
                g[v] = 'U';
                if (g[v - n] == '#') g[v - n] = 'D';
            } else if (i < n - 1 && to[v + n] == -1) {
                g[v] = 'D';
                if (g[v + n] == '#') g[v + n] = 'U';
            } else if (j < n - 1 && to[v + 1] == -1) {
                g[v] = 'R';
                if (g[v + 1] == '#') g[v + 1] = 'L';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int v = i * n + j;
            if (g[v] == '#') {
                cout << "INVALID\n";
                return 0;
            }
        }
    }
    cout << "VALID\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int v = i * n + j;
            cout << g[v];
        }
        cout << '\n';
    }
}