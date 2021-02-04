#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
void disp(vector<T> vec) {
	for (T element : vec)
		cout << element << " ";
	cout << endl;
}

vector<int> nxt, prv;

void small(vector<ll>& a) {
	int n = a.size();
	nxt.resize(n); prv.resize(n);
	stack<int> st; st.push(0);
	for (int i = 1; i < n; i++) {
		while (!st.empty() && a[st.top()] > a[i]) {
			nxt[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		nxt[st.top()] = -1;
		st.pop();
	}
	st.push(n - 1);
	for (int i = n - 2; i >= 0; i--) {
		while (!st.empty() && a[st.top()] > a[i]) {
			prv[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		prv[st.top()] = -1;
		st.pop();
	}
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	vector<ll> a(n), left(n), right(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	small(a);
	for (int l = 0; l < n; l++) {
		int l1 = prv[l], r = n - l - 1, r1 = nxt[r];

		if (l1 == -1) left[l] = (l + 1) * a[l];
		else left[l] = left[l1] + (l - l1) * a[l];

		if (r1 == -1) right[r] = (n - r) * a[r];
		else right[r] = right[r1] + (r1 - r) * a[r];
	}
	ll mx = -1, ind = -1;
	for (int i = 0; i < n; i++) {
		if (mx > left[i] + right[i] - a[i]) continue;
		mx = left[i] + right[i] - a[i];
		ind = i;
	}
	for (int i = ind + 1; i < n; i++)
		a[i] = min(a[i - 1], a[i]);

	for (int i = ind - 1; i >= 0; i--)
		a[i] = min(a[i + 1], a[i]);

	disp(a);
}