#include<bits/stdc++.h>
using namespace std;
int counts[26];
bool check(char c)
{
	int ind = c - 'a';
	for (int i = 0; i < ind; i++)
		if (counts[i] > 0)
			return false;
	return true;
}
int main()
{
	string s;
	int ind = 0;
	cin >> s;
	stack<char> t;
	vector<char> u;

	int len = s.length();
	for (int i = 0; i < 26; i++)
		counts[i] = 0;
	for (int i = 0; i < len; i++)
		counts[s[i] - 'a']++;

	t.push('1');
	for (int i = 0; i < len; i++)
	{
		t.push(s[i]);
		counts[s[i] - 'a']--;
		while (check(t.top()) && t.top() != '1')
		{
			u.push_back(t.top());
			t.pop();
		}

	}
	while (t.top() != '1')
	{
		u.push_back(t.top());
		t.pop();
	}
	for (int i = 0; i < len; i++)
		cout << u[i];
	cout << endl;
}