#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000
int main()
{
    ll n;
    cin >> n;
    vector<ll> a;
    ll temp;
    for (ll i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp) a.push_back(temp);
    }
    n = a.size();
    if (n > 122)
        cout << 3 << endl;
    else
    {
        vector<pair<ll, ll>> adj[n];
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                else if (a[i]&a[j])
                    adj[i].push_back(make_pair(j, 1));
                else continue;
            }
        ll mini = INF;
        for (ll x = 0; x < n; x++)
        {
            ll ind = 0;
            priority_queue<pair<ll, ll>> q;
            for (auto j : adj[x])
            {
                adj[x].erase(adj[x].begin() + ind);
                ll distance[n];
                bool processed[n];
                for (ll i = 0; i < n; i++) {
                    distance[i] = INF;
                    processed[i] = false;
                }
                distance[x] = 0;
                q.push({0, x});
                while (!q.empty()) {
                    ll a = q.top().second; q.pop();
                    if (processed[a]) continue;
                    processed[a] = true;
                    for (auto u : adj[a]) {
                        ll b = u.first, w = u.second;
                        if (distance[a] + w < distance[b]) {
                            distance[b] = distance[a] + w;
                            q.push({ -distance[b], b});
                        }
                    }
                }
                mini = min(mini, distance[j.first] + 1);
                adj[x].push_back(j);
                ind++;
            }
        }
        if (mini >= INF)
            cout << -1 << endl;
        else cout << mini << endl;
    }

}