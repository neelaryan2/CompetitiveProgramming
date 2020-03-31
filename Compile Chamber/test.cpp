vector<int> arr(n);
vector<int> sums(rt + 1);
void update(int i, int j, int x) {
	int n = arr.size();
	if (i > j) return;
	if (i < 0) return update(0, j);
	if (j >= n) return update(i, n - 1);
	int rt = sqrt(n);
	int ri = i / rt, rj = j / rt;
	if (ri == rj) {
		for (int it = i; it <= j; it++) {
			arr[it] += x;
			sums[ri] += x;
		}
		return;
	}
	for (int it = ++ri; it < rj; it++)
		sums[it] += rt * x;
	update(i, ri * rt - 1);
	update(rj * rt, j);
}
int query(int i, int j) {
	int n = state.size();
	if (i > j) return 0;
	if (i < 0) return query(0, j);
	if (j >= n) return query(i, n - 1);
	int rt = sqrt(n);
	int ri = i / rt, rj = j / rt;
	int ans = 0;
	if (ri == rj) {
		for (int it = i; it <= j; it++)
			ans += arr[it];
		return ans;
	}
	for (int it = ++ri; it < rj; it++)
		ans += sums[it];
	ans += query(i, ri * rt - 1);
	ans += query(rj * rt, j);
	return ans;
}