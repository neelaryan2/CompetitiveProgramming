#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ppi = pair<int, pii>;
using vpi = vector<pii>;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define runtime() (int)(1000 * ((double)clock()) / CLOCKS_PER_SEC)
using vi = vector<int>;
const int N = 1e6 + 10;
int least[N], ind[N];
vector<int> primes;
vector<vi> adj;
void sieve() {
    least[0] = 0;
    least[1] = 1;
    for (int i = 2; i < N; i++)
        least[i] = (i % 2) ? i : 2;
    for (int i = 3; i <= N / i; i += 2) {
        if (least[i] != i) continue;
        for (int j = i * i; j < N; j += i)
            if (least[j] == j)
                least[j] = i;
    }
    for (int i = 1; i < N; i++) {
        if (least[i] == i) {
            ind[i] = primes.size();
            primes.pb(i);
        } else
            ind[i] = -1;
    }
}
int shortest_cycle(int source) {
    int ans = N;
    int n = primes.size();
    vector<int> dist(n, N);
    vector<int> par(n, -1);
    queue<int> q;
    q.push(source);
    dist[source] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : adj[v]) {
            if (dist[to] == N) {
                dist[to] = 1 + dist[v];
                par[to] = v;
                q.push(to);
            } else if (par[v] != to and par[to] != v)
                ans = min(ans, dist[v] + dist[to] + 1);
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, mx = -1;
    cin >> n;
    sieve();
    adj.resize(primes.size());
    map<pii, bool> vis;
    int ans = N;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mx = max(mx, a);
        vector<int> v;
        while (a > 1) {
            int p = least[a], cnt = 0;
            while (a % p == 0) a /= p, cnt++;
            if (cnt % 2) v.pb(p);
        }
        if (v.empty()) {
            cout << "1\n";
            return 0;
        }
        if (v.size() > 2) assert(false);
        if (v.size() == 1) v.pb(1);
        if (v[0] > v[1]) swap(v[0], v[1]);
        int u1 = ind[v[0]], u2 = ind[v[1]];
        pii p = {u1, u2};
        auto it = vis.find(p);
        if (it != vis.end())
            ans = 2;
        else
            vis[p] = true;
        adj[u1].pb(u2);
        adj[u2].pb(u1);
    }
    if (ans != N) {
        cout << ans << '\n';
        return 0;
    }
    int up = sqrtl(mx);
    for (int i = 0; primes[i] <= up; i++) {
        ans = min(ans, shortest_cycle(i));
    }
    if (ans == N) ans = -1;
    cout << ans << '\n';
}