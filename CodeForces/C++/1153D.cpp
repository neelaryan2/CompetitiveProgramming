#include<bits/stdc++.h>
using namespace std;
#define N 300009
vector<bool> type;
vector<int> adj[N];
int dp[N];
int cnt = 0;

void dfs(int v) {
    if (adj[v].empty()) {
        dp[v] = 1;
        cnt++;
    }
    else {
        dp[v] = (type[v]) ? INT_MAX : 0;
        for (int i : adj[v]) {
            dfs(i);
            if (type[v])
                dp[v] = min(dp[v], dp[i]);
            else
                dp[v] += dp[i];
        }
    }
}
int main() {
    int n, stor;
    cin >> n;
    type.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> stor;
        type.push_back(stor);
    }
    for (int i = 2; i <= n; i++) {
        cin >> stor;
        adj[stor].push_back(i);
    }
    dfs(1);
    cout << cnt + 1 - dp[1] << endl;
}