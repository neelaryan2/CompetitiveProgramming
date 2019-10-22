#include<bits/stdc++.h>
using namespace std;
vector<string> s, minstr, s1, s2;
vector<int> indices;

bool compare(int i, int j) {
	if (minstr[i] < minstr[j])
		return true;
	if (minstr[i] > minstr[j])
		return false;
	return i < j;
}

bool comp(string a1, string a2) {
	for (int i = 0; i < min(a1.size(), a2.size()); i++) {
		if (a1[i] < a2[i])
			return true;
		if (a1[i] > a2[i])
			return false;
	}
	return a1.size() >= a2.size();
}
void duval(int t) {
	int n = s[t].size();
	int i = 0;
	while (i < n) {
		int j = i + 1, k = i;
		while (j < n && s[t][k] >= s[t][j]) {
			if (s[t][k] > s[t][j])
				k = i;
			else
				k++;
			j++;
		}
		while (i <= k) {
			if (t) s2.push_back(s[t].substr(i, j - k));
			else s1.push_back(s[t].substr(i, j - k));
			i += j - k;
		}
	}
}
string min_cyclic_string(string s) {
	s += s;
	int n = s.size();
	int i = 0, ans = 0;
	while (i < n / 2) {
		ans = i;
		int j = i + 1, k = i;
		while (j < n && s[k] <= s[j]) {
			if (s[k] < s[j])
				k = i;
			else
				k++;
			j++;
		}
		while (i <= k)
			i += j - k;
	}
	return s.substr(ans, n / 2);
}

size_t getMax(vector<string> arr, int n) {
	size_t max = arr[0].size();
	for (int i = 1; i < n; i++) {
		if (arr[i].size() > max)
			max = arr[i].size();
	}
	return max;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, count = 1;
	cin >> n;
	string t;
	for (int i = 0; i < n; i++)
		cin >> t, s.push_back(t), minstr.push_back(min_cyclic_string(t)), indices.push_back(i);
	sort(indices.begin(),indices.end(),compare);
	for (int i = 1; i < n; i++)
		if (minstr[indices[i]] != minstr[indices[i - 1]])
			count++;
	cout << count << endl;

	duval(0);
	duval(1);

	int ind1 = 0, ind2 = 0, n1 = s1.size(), n2 = s2.size();
	while (ind1 < n1 && ind2 < n2) {
		if (comp(s1[ind1], s2[ind2]))
			cout << s1[ind1], ind1++;
		else cout << s2[ind2], ind2++;
	}
	if (ind2 == n2)
		while (ind1 < n1)
			cout << s1[ind1], ind1++;
	if (ind1 == n1)
		while (ind2 < n2)
			cout << s2[ind2], ind2++;
	cout << endl;
}