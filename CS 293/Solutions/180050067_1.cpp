#include<bits/stdc++.h>
using namespace std;

const int N=1000000;
char type[N];
int num[N];
int diff[N + 1];
bool nest1[N + 1];
bool nest2[N + 1];
int mini[N + 1];
int diff2[N + 1];
int ans[N];

int difference(char a[], int b[], int c[], bool d[], bool e[], int n, int k)
{
	for (int j = 0; j < n; j++)
	{
		d[b[j]] = true;
		e[b[j]] = true;
		c[b[j]] = 0;
	}
	for (int i = k - 1; i < n + k - 1; i++)
	{
		int t = i % n;
		if (a[t] == 's') c[b[t]]++;
		else c[b[t]]--;
		if (c[b[t]] < 0) d[b[t]] = false;
	}
	for (int i = 0; i < n; i++)
		if (c[b[i]] != 0)
		{
			d[b[i]] = false;
			e[b[i]] = false;
		}
	int count = 0;

	for (int i = 1; i < N+1; i++)
		if (d[i]) count++;

	return count;
}
void minim(char a[], int b[], int c[], int m[], int n)
{
	for (int i = 0; i < n; i++)
	{
		c[b[i]] = 0;
		m[b[i]] = N;
	}
	for (int t = 0; t < n; t++)
	{
		if (a[t] == 's') c[b[t]]++;
		else c[b[t]]--;
		if (c[b[t]] < m[b[t]]) m[b[t]] = c[b[t]];
	}
}

int main()
{
	int n, index = 1;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> type[i] >> num[i];
	for (int i = 1; i < n + 1; i++)
	{	diff2[i] = 0;
		diff[i] = 0;
	}
	minim(type, num, diff, mini, n);
	int temp = difference(type, num, diff, nest1, nest2, n, 1);
	//cout<<temp<<endl;
	for (int i = 0; i < n; i++)
	{
		ans[i] = temp;
		if (nest2[num[i]])
		{
			if (type[i] == 's')
			{
				if (nest1[num[i]]) 
				{
					temp--;
					nest1[num[i]] = not(nest1[num[i]]);
				}
				diff2[num[i]]++;
			}
			else
			{
				if (diff2[num[i]] == mini[num[i]] + 1)
				{
					temp++;
					diff2[num[i]]--;
					nest1[num[i]] = true;
				}
				else diff2[num[i]]--;
			}
		}
		else if (type[i] == 's') diff2[num[i]]++;
		else diff2[num[i]]--;
	}
	int maxi = -N;

	for (int i = n - 1; i >= 0; i--)
		if (ans[i] >= maxi) {
			maxi = ans[i];
			index = i;
		}

	cout << index + 1 << " " << ans[index] << endl;
}







