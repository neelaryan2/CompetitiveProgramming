#include<bits/stdc++.h>
using namespace std;

vector<string> s;
set<string> st;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, len; long long ans = 0;
	cin >> n >> len; s.resize(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			string curr = "";
			for (int k = 0; k < len; k++) {
				if (s[i][k] == s[j][k]) curr += s[i][k];
				else if (s[i][k] != 'S' && s[j][k] != 'S') curr += 'S';
				else if (s[i][k] != 'E' && s[j][k] != 'E') curr += 'E';
				else if (s[i][k] != 'T' && s[j][k] != 'T') curr += 'T';
			}
			if (st.find(curr) != st.end())
				ans++;
		}
		st.insert(s[i]);
	}
	cout << ans << endl;
}