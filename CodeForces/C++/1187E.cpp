    #include<bits/stdc++.h>
    using namespace std;
    vector<int> adj[200009];
    int sizes[200009];
    long long best = -INT_MAX;
    int n;
    long long defscore = 0;
     
    void initsize(int v, int parent) {
    	if (adj[v].empty())
    		return initsize(v + 1, -1);
    	sizes[v] = 1;
    	for (auto i : adj[v]) {
    		if (i != parent) {
    			initsize(i, v);
    			sizes[v] += sizes[i];
    		}
    	}
    	defscore += sizes[v];
    }
     
    void dfs(int v, int parent, long long curr) {
    	if (adj[v].empty())
    		return dfs(v + 1, -1, defscore);
    	best = max(best, curr);
    	for (auto i : adj[v]) {
    		if (i != parent) {
    			dfs(i, v, curr + n - 2 * sizes[i]);
    		}
    	}
    }
     
    int main() {
    	int x, y;
    	cin >> n;
    	for (int i = 1; i < n; i++)	{
    		cin >> x >> y;
    		--x;
    		--y;
    		adj[x].push_back(y);
    		adj[y].push_back(x);
    	}
    	initsize(0, -1);
    	dfs(0, -1, defscore);
    	cout << best << endl;
    }