#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;


set<int> s2;
set<int> s1[200005];

int cnt, n;
void bfs(int s)
{
	queue<int> q;
	q.push(s);
	s2.erase(s2.find(s));
	while (!q.empty())
	{
		int v = q.front();
		cnt++;
		q.pop();
		vector<int> aux;
		for (auto it = s2.begin(); it != s2.end(); it++)
		{
			int u = (*it);
			if (s1[v].find(u) == s1[v].end())
			{
				aux.pb(u);
				q.push(u);
			}
		}
		for (int i = 0; i < aux.size(); i++)
			s2.erase(s2.find(aux[i]));
	}
}

vector<int> v;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m;
	cin >> n >> m;
	int a, b;
	while (m--)
	{
		cin >> a >> b;
		s1[a].insert(b);
		s1[b].insert(a);
	}
	for (int i = 1; i <= n; i++)
	{
		s2.insert(i);
	}


	for (int i = 1; i <= n; i++)
	{
		if (s2.find(i) != s2.end())
		{

			cnt = 0;
			bfs(i);
			v.pb(cnt);
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}