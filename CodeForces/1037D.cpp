#include<bits/stdc++.h>
using namespace std;
#define N 200006

int pos[N];
vector <int> adj[N];

bool com(int a, int b)
{
    return pos[a] < pos[b];
}

int main()
{
    int n, x, y;
    cin >> n;
    bool v[n + 10];
    memset(v, false, sizeof(v));
    queue <int> q;

    int ans[n + 10];
    bool answ = true;

    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int given_bf[n + 10];

    for (int i = 0; i < n; i++)
    {
        cin >> given_bf[i];
        pos[given_bf[i]] = i;
    }
    if (given_bf[0] != 1)
    {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end(), com);

    int j = 0;
    int s = given_bf[0];
    q.push(s);
    v[s] = true;
    ans[j] = s;
    j++;
    while (!q.empty())
    {
        int r = q.front();
        q.pop();
        for (auto u : adj[r])
        {
            if (v[u]) continue;
            v[u] = true;
            ans[j] = u;
            j++;
            q.push(u);
        }
    }

    for (int i = 0; i < n; i++)
        if (given_bf[i] != ans[i])
            answ = false;

    if (answ) cout << "Yes" << endl;
    else cout << "No" << endl;
}