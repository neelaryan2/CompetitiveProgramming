#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define fi first
#define se second
#define pii pair<int, int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<bool> is(n);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        is[i] = c;
    }
    vector<int> par(n), deg(n);
    int start = -1, mx = -1;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        par[i] = c - 1;
        if (c) deg[--c]++;
    }
    for (int i = 0; i < n; i++) {
        if (!is[i]) continue;
        int ind = i, cnt = 0;
        while (par[ind] != -1 && deg[par[ind]] == 1)
            ind = par[ind], cnt++;
        if (cnt > mx) {
            mx = cnt, start = i;
        }
    }
    cout << ++mx << endl;
    vector<int> ans(1, start);
    while (par[start] != -1 && deg[par[start]] == 1)
        start = par[start], ans.push_back(start);
    for (int i = ans.size(); i > 0; i--)
        cout << ++ans[i - 1] << " ";
    cout << endl;
}