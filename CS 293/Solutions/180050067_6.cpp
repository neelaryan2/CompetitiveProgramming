#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1000007;

vector<pair<int, int>> actions;
int a[N];
stack<int> st;
ll w[N], pr[N] = {0};

void swap(int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
	actions.push_back(make_pair(i, j));
}

int main() {
	ll n, temp, tempo = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> w[i];
	for (int i = 1; i < n; i++) {
		cin >> temp;
		pr[i] = pr[i - 1] + temp;
	}

	for (int i = 0; i < n; i++)
		tempo += w[i] * abs(pr[i] - pr[a[i]]);
	cout << tempo << endl;

	for (int i = n - 1; i >= 0; i--) {
		if (a[i] > i) {
			tempo = a[i];
			while (a[tempo] > i)
				st.push(tempo), tempo = a[tempo];
			st.push(tempo);
			temp = i;
			while (!st.empty()) {
				swap(temp, st.top());
				temp = st.top(), st.pop();
			}
		}
	}
	cout << actions.size() << endl;
	for (int i = 0; i < actions.size(); i++)
		cout << actions[i].first << " " << actions[i].second << endl;
}