#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second
#define Point pair<int, int>

bool onSegment(Point p, Point q, Point r) {
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
	        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;
	return false;
}
int orientation(Point p, Point q, Point r) {
	int val = (q.y - p.y) * (r.x - q.x) -
	          (q.x - p.x) * (r.y - q.y);
	if (val == 0) return 0;
	return (val > 0) ? 1 : 2;
}
bool intersect(Point p1, Point q1, Point p2, Point q2) {
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);
	if (o1 != o2 && o3 != o4) return true;
	if (o1 == 0 && onSegment(p1, p2, q1)) return true;
	if (o2 == 0 && onSegment(p1, q2, q1)) return true;
	if (o3 == 0 && onSegment(p2, p1, q2)) return true;
	if (o4 == 0 && onSegment(p2, q1, q2)) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int R, B;
	cin >> R >> B;
	// puts((R == B) ? "Yes" : "No");
	// return 0;
	if (R != B) {
		puts("No");
		return 0;
	}
	int n = R;
	vector<pii> ships(n), bases(n);
	for (int i = 0; i < n; i++)
		cin >> ships[i].x >> ships[i].y;
	for (int i = 0; i < n; i++)
		cin >> bases[i].x >> bases[i].y;
	sort(bases.begin(), bases.end());
	do {
		bool flag = true;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (intersect(ships[i], bases[i], ships[j], bases[j])) {
					flag = false; break;
				}
		if (flag) {
			puts("Yes");
			return 0;
		}
	} while (next_permutation(bases.begin(), bases.end()));
	puts("No");
}