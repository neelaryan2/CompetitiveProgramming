#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, counts = 0;
		cin >> n;

		int a[n];

		for (int i = 0; i < n; i++)
			cin >> a[i];

		for (int i = 0; i < n - 1; i++)
			if (a[i] > a[i + 1]) counts++;

		if (a[n - 1] > a[0]) counts++;

		if (counts < 2)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}