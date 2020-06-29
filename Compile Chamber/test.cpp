/* AUTHOR - SHASHANK AGRAWAL (codeforces - @shashanka136) ( codechef - @shashank_vasu) */
#include <bits/stdc++.h>
#pragma optimize("-O3")
using namespace std;
#ifdef TRACE
#include "../trace.h"
#else
#define trace(args...)
#endif
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;		typedef vector<int> vi;
typedef vector<vl> vvl;	  	typedef vector<vi> vvi;
typedef pair<ll, ll> pll;	typedef pair<int, int> pii;
typedef vector<pll> vpl;	typedef vector<pii> vpi;
typedef vector<vpl> vvpl;	typedef vector<vpi> vvpi;
#define S second
#define F first
#define V vector
#define MP make_pair
#define PB push_back
#define POB pop_back
#define PF push_front
#define POF pop_front
#define sz(x) (int)x.size()
#define f(i,j,k,l) for(ll i =(ll)j; i!=(ll)k; i = i + l) 
#define INP(v,n) f(i,0,n,1) cin>>v[i];
#define OUT(v,n) f(i,0,n,1){ cout<<v[i]<<" ";}cout<<endl;
#define endl '\n'
#define all(v) v.begin(), v.end()
const ll mod = 998244353;
const int N =300005;

struct bridges{
	int n,m; // number of nodes
	vector<int> *tree; // adjacency list of graph
	vector<int> *adj;
	bool* vis, *isbr;
	int* tin,*low,*us,*vs;
	int cmpno;
	int timer;
	queue<int> *q;
	bridges(){}
	bridges(int _n, int _m): n(_n), m(_m){
		cmpno = 0;
		tree = new vector<int>[n+1];
		adj = new vector<int>[n+1];
		vis = new bool[n+1];
		isbr = new bool[m+1];
		tin = new int[n+1];
		low = new int[n+1];
		us = new int[m+1];
		vs = new int[m+1];
		q = new queue<int>[n+1];
	}

	int nxt(int u,int e){
	    return us[e]==u? vs[e]:us[e];
	}

	void get_edges(){
		for(int i = 0; i<m; i++){
			cin>>us[i]>>vs[i];
			us[i]--;vs[i]--;
			adj[us[i]].push_back(i);
			adj[vs[i]].push_back(i);
		}
	}

	void dfs0(int i, int p = -1) {
		vis[i] = true;
		tin[i] = low[i] = timer++;
		for (int x : adj[i]) {
			int nx = nxt(i,x);
			if (nx == p) continue;
			if (vis[nx]) {
				low[i] = min(low[i], tin[nx]);
			} else {
				dfs0(nx, i);
				low[i] = min(low[i], low[nx]);
				if (low[nx] > tin[i])
					isbr[x] = true;//i-x is a bridge
			}
		}
	}

	void find_bridges(){
		timer = 0;
		fill(vis,vis+n+1,false);
		fill(tin,tin+n+1,-1);
		fill(low,low+n+1,-1);
		for (int i = 0; i < n; ++i) {
			if (!vis[i])
				dfs0(i);
		}
	}
	//here starts the formation of bridge tree, we already found
	//the bridge edges in the graph
	void dfs1(int v){
		int crcmp = cmpno;//current component number
		q[crcmp].push(v);//during this dfs/bfs we may go to
		//other component that's why different queue for every component
		vis[v] = 1;
		while(!q[crcmp].empty()){// exploring current component
			int u = q[crcmp].front();
			q[crcmp].pop();
			for(int x : adj[u]){
				int nx = nxt(u,x);
				if(vis[nx]) continue;
				if(isbr[x]){
					cmpno++;
					tree[crcmp].push_back(cmpno);
					tree[cmpno].PB(crcmp);
					dfs1(nx);
				}else{
					q[crcmp].push(nx);
					vis[nx] = 1;
				}
			}

		}
	}

	void find_components(){
		cmpno = 0;
		fill(vis,vis+n+1,false);
		for(int i = 0; i < n; i++){
			if(!vis[i])
				dfs1(i);
		}
	}

};

int n,m;
int ans = 0;
bridges lol(N+3,N+3);
void ins(int z, int &mx1, int &mx2){
	if(z >= mx1){
		mx2 = mx1;
		mx1 = z;
	}else if(z >= mx2){
		mx2 = z;
	}
}

int dfs(int i, int p){
	int mx1 = 0,mx2 = 0;
	for(auto x : lol.tree[i]){
		if(x == p) continue;
		int z = dfs(x,i);
		ins(z,mx1,mx2);
	}
	ans = max(ans,mx1+mx2);
	return mx1+1;
}	

void solve(){
	cin>>n>>m;
	lol.n = n;
	lol.m = m;
	lol.get_edges();
	lol.find_bridges();
	lol.find_components();
	lol.cmpno++;
	dfs(0,-1);
	cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	t = 1;
	while(t--){
		solve();
	}
}