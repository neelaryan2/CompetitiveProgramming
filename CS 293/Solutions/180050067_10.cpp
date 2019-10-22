#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> tree;

int counts(int index) {
	int sum = 0;
	for (int i = index; i >= 1; i -= i & -i)
		sum += tree[i];
	return sum;
}
void update(int index) {
	for (int i = index; i <= tree.size(); i += i & -i)
		tree[i]++;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
		tree.push_back(0);

	ll curr, lesser, greater, temp, ans1, ans2;
	ans1 = ans2 = temp = lesser = greater = 0;

	for (int i = 0; i < n; i++) {
		cin >> curr;
		lesser = counts(curr), greater = i - lesser;
		temp = n - curr - greater < 2 ? 0 : n - curr - greater;
		temp = (temp * (temp - 1)) / 2 - lesser * (n - curr - greater);
		ans1 += temp;
		ans2 += lesser * greater - temp;
		update(curr);
	}
	cout << ans1  << " " << ans2  << endl;
}
