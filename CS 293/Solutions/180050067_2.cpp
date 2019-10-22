#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ll x;
	string s;
	ll pos = 0;

	cin >> s >> x;
	int len = s.length();

	int smod[len];
	int news[len];
	int count[26];
	int count2[26];
	ll fac[len + 1];
	ll temp;
	int newlet;

	for (int i = 0; i < len; i++)
		smod[i] = s[i] - 'a';

	for (int i = 0; i < 26; i++)
	{
		count[i] = 0;
		count2[i] = 0;
	}

	for (int i = 0; i < len; i++)
	{
		count[smod[i]]++;
		count2[smod[i]]++;
	}
	bool t = true;
	fac[0] = 1;
	fac[1] = 1;
	for (int i = 2; i <= len; i++)
		fac[i] = i * fac[i - 1];

	for (int i = 0; i < len; i++)
	{
		for (int k = 0; k < 26; k++)
		{
			if (count[k] > 0 && (smod[i] > k))
			{
				count[k]--;
				temp = fac[len - 1 - i];
				for (int j = 0; j < 26; j++)
					temp /= fac[count[j]];
				pos += temp;
				count[k]++;
			}
			if (count2[k] > 0 && t)
			{
				count2[k]--;
				temp = fac[len - 1 - i];
				for (int j = 0; j < 26; j++)
					temp /= fac[count2[j]];
				if (x < temp)
				{
					t = false;
					newlet = k;
				}
				else
					x -= temp;
				count2[k]++;
			}
		}
		count[smod[i]]--;
		news[i] = newlet;
		t = true;
		count2[newlet]--;
	}

	for (int i = 0; i < len; i++)
		news[i] += 'a';

	cout << pos << " ";

	for (int i = 0; i < len; i++)
		cout << char(news[i]);
	cout << endl;
}