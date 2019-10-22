#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define x first
#define y second
vector<ii> reds;
vector<ii> blues;
multiset<int> store;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, i, j, count = 0;
	cin >> n;
	ii temp;
	for (i = 0; i < n; ++i) {
		cin >> temp.x >> temp.y;
		reds.push_back(temp);
	}
	for (i = 0; i < n; ++i) {
		cin >> temp.x >> temp.y;
		blues.push_back(temp);
	}
	sort(reds.begin(), reds.end());
	sort(blues.begin(), blues.end());
	i = j = n - 1;
	while (i >= 0) {
		while (reds[i].x <= blues[j].x && j >= 0)
			store.insert(blues[j].y), j--;
		auto it = store.lower_bound(reds[i].y);
		if (it != store.end())	
			count++, store.erase(it);
		i--;
	}
	cout << count << endl;
	return 0;
}