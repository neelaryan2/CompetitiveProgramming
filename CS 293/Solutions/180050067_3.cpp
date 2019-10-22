#include<bits/stdc++.h>
using namespace std;
vector<int> p, q, r;

void mult(int pin, int qin, int rin, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			r[rin + i + j] += p[i + pin] * q[j + qin];
}
void poly_mult(int pin, int qin, int rin, int n)
{
	if (n <= 16)
	{
		mult(pin, qin, rin, n);
		return;
	}
	for (int i = 0; i < n / 2; i++)
	{
		p[i + pin] += p[i + pin + n / 2];
		q[i + qin] += q[i + qin + n / 2];
	}
	poly_mult(pin, qin, rin + n / 2, n / 2);
	for (int i = 0; i < n / 2; i++)
	{
		p[i + pin] -= p[i + pin + n / 2];
		q[i + qin] -= q[i + qin + n / 2];
	}
	vector<int> temp;
	
	for (int i = 0; i < n - 1; i++)
	{
		temp.push_back(r[i + rin + n / 2]);
		r[i + rin + n / 2] = 0;
	}
	poly_mult(pin, qin, rin, n / 2);
	poly_mult(pin + n / 2, qin + n / 2, rin + n, n / 2);
	for (int i = 0; i < n - 1; i++)
		temp[i] = temp[i] - r[i + rin] - r[i + rin + n];
	for (int i = 0; i < n - 1; i++)
		r[i + rin + n / 2] += temp[i];
	}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	int stor;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> stor;
		p.push_back(stor);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> stor;
		q.push_back(stor);
	}
	for (int i = 0; i < 2 * n - 1; i++)
		r.push_back(0);

	poly_mult(0, 0, 0, n);

	for (int i = 0; i < 2 * n - 1; i++)
		cout << r[i] << " ";
	cout << endl;
}