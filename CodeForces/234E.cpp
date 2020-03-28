#include<bits/stdc++.h>
using namespace std;
const int t = 4;
#define fi first
#define se second

map<string, int> rating;
int x, a, b, c;
int gen(int s) {
	int res = (x * a + b) % c;
	x = res; return res % s;
}
bool cmp(const string& s1, const string& s2) {
	return rating[s1] > rating[s2];
}
struct scmp {
	bool operator() (const string& s1, const string& s2) const {
		return cmp(s1, s2);
	}
};
vector<set<string, scmp>> bask;
vector<set<string, scmp>> grp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n; cin >> n;
	int m = n / t;
	grp.resize(m);
	bask.resize(t);
	cin >> x >> a >> b >> c;

	vector<string> vec(n);
	for (int i = 0; i < n; i++) {
		string s; int r;
		cin >> s >> r;
		rating[s] = r;
		vec[i] = s;
	}

	sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < t; i++)
		for (int j = 0; j < m; j++)
			bask[i].insert(vec[j + i * m]);

	for (int i = 0; i < m; i++) {
		int sz = bask[0].size();
		for (int j = 0; j < t; j++) {
			int ind = gen(sz);
			auto it = bask[j].begin();
			advance(it, ind);
			grp[i].insert(*it);
			bask[j].erase(it);
		}
	}
	char c = 'A';
	for (auto s : grp) {
		cout << "Group " << c++ << ":\n";
		for (string st : s)
			cout << st << endl;
	}
}