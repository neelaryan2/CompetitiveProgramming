#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = LLONG_MAX;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll m, w, p, n;
	cin >> m >> w >> p >> n;
	ll passes = 0, curr = 0, run = inf;
	ll step, mw, total, nxt;
	while (curr < n) {
		step = (m > inf / w) ? 0 : (p - curr) / (m * w);
		if (step <= 0) {
			mw = curr / p;
			if (m >= w + mw) w += mw;
			else if (w >= m + mw) m += mw;
			else {
				total = m + w + mw;
				m = total / 2;
				w = total - m;
			}
			curr %= p;
			step = 1;
		}
		passes += step;
		if (step * m > inf / w) curr = inf;
		else {
			curr += step * m * w;
			nxt = ceil((n - curr) / (m * w * 1.0));
			run = min(run, passes + nxt);
		}
	}
	cout << min(run, passes) << "\n";
}
