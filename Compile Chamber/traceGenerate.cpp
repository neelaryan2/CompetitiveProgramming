#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; i < (n); (i)++)
#define repr(i, n) for(int (i) = (n) - 1; i >= 0; (i)--)
#define vb vector<bool>
#define endl "\n"

vb getBinary(int num, int s) {
	int n = abs(num);
	vb a(s, 0);
	for (int i = 0; i < s && n; i++)
		a[i] = n & 1, n >>= 1;
	reverse(a.begin(), a.end());
	if (num >= 0) return a;
	rep(i, s) a[i] = !a[i];
	int i = int(a.size()) - 1;
	while (i >= 0 && a[i]) a[i--] = 0;
	if (i >= 0) a[i] = 1;
	return a;
}

void lab2q1();
void lab2q2();
void lab3q1();
void lab3q2();
void lab3q3();
void lab4q1();
void lab5q1();
void hw5q1();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("out.txt", "w", stdout);
	lab5q1();
	return 0;
}

void lab2q1() {
	const int k = 4;
	rep(i, 1 << k) {
		vb a1 = getBinary(i, k);
		rep(j, 1 << k) {
			vb a2 = getBinary(j, k);
			rep(t, 1 << 2) {
				vb a4, a3 = getBinary(t, 2);
				if (t == 3) a4 = getBinary((i & 3) * (j & 3), k + 1);
				else if (t == 2) a4 = getBinary(~(i & j), k + 1), a4[0] = 0;
				else if (t == 1) a4 = getBinary(i - j, k + 1);
				else if (t == 0) a4 = getBinary(i + j, k + 1);
				for (auto e : a1) cout << e;
				for (auto e : a2) cout << e;
				for (auto e : a3) cout << e;
				cout << " ";
				if (t == 1 && i < j) cout << "0";
				else if (t == 1) cout << "1";
				else cout << a4[0];
				rep(r, k) cout << a4[r + 1];
				cout << " ";
				rep(r, k + 1) cout << "1";
				cout << "\n";
			}
		}
	}
}
void lab2q2() {
	const int k = 4;
	rep(i, 1 << k) {
		vb a1 = getBinary(i, k);
		rep(j, 1 << k) {
			vb a2 = getBinary(j, k);
			vb a3 = getBinary(i * j, 2 * k);
			for (auto e : a1) cout << e;
			for (auto e : a2) cout << e;
			cout << " ";
			for (auto e : a3) cout << e;
			cout << " ";
			rep(t, 2 * k) cout << "1";
			cout << "\n";
		}
	}
}
void lab3q1() {
	const int k = 8;
	rep(i, 1 << k) {
		vb a1 = getBinary(i, k);
		rep(j, 1 << k) {
			vb a2 = getBinary(j, k);
			vb a3 = getBinary(i + j, k + 1);
			for (auto e : a1) cout << e;
			for (auto e : a2) cout << e;
			cout << " ";
			for (auto e : a3) cout << e;
			cout << " ";
			rep(t, k + 1) cout << "1";
			cout << "\n";
		}
	}
}
void lab3q2() {
	const int k = 8;
	rep(i, 1 << k) {
		vb a1 = getBinary(i, k);
		rep(j, 1 << k) {
			vb a2 = getBinary(j, k);
			rep(t, 1 << 2) {
				vb a4, a3 = getBinary(t, 2);
				if (t == 3) a4 = getBinary(i ^ j, k + 1), a4[0] = 0;
				else if (t == 2) a4 = getBinary(i & j, k + 1), a4[0] = 0;
				else if (t == 1) a4 = getBinary(i - j, k + 1);
				else if (t == 0) a4 = getBinary(i + j, k + 1);
				for (auto e : a1) cout << e;
				for (auto e : a2) cout << e;
				for (auto e : a3) cout << e;
				cout << " ";
				if (t == 1 && i < j) a4[0] = 0;
				else if (t == 1) a4[0] = 1;
				bool an = 1;
				rep(r, k + 1) cout << a4[r];
				rep(r, k) an = an && !a4[r + 1];
				if (!an) cout << "0";
				else cout << "1";
				cout << " ";
				rep(r, k + 2) cout << "1";
				cout << "\n";
			}
		}
	}
}
void lab3q3() {
	const int k = 8;
	rep(i, 1 << k) {
		vb a1 = getBinary(i, k);
		rep(j, 1 << k) {
			vb a2 = getBinary(j, k);
			rep(t, 1 << 2) {
				vb a4, a3 = getBinary(t, 2);
				if (t == 3) a4 = getBinary(i ^ j, k + 1), a4[0] = 0;
				else if (t == 2) a4 = getBinary(i & j, k + 1), a4[0] = 0;
				else if (t == 1) a4 = getBinary(i - j, k + 1);
				else if (t == 0) a4 = getBinary(i + j, k + 1);
				for (auto e : a1) cout << e;
				for (auto e : a2) cout << e;
				for (auto e : a3) cout << e;
				cout << " ";
				if (t == 1 && i < j) a4[0] = 0;
				else if (t == 1) a4[0] = 1;
				rep(r, k + 1) cout << a4[r];
				if (i == j) cout << "010";
				else if (i > j) cout << "100";
				else cout << "001";
				cout << " ";
				rep(r, k + 4) cout << "1";
				cout << "\n";
			}
		}
	}
}
void lab4q1() {
	const int k = 4;
	rep(en , 1 << 1) {
		rep(i, 1 << k) {
			vb a = getBinary(i, k);
			cout << en;
			for (auto e : a) cout << e;
			cout << " ";
			if (!en || !i) {
				cout << "000 001\n";
				continue;
			}
			if (i >= 8) cout << "111";
			else if (i >= 4) cout << "101";
			else if (i >= 2) cout << "011";
			else if (i >= 1) cout << "001";
			cout << " 111";
			cout << "\n";
		}
	}
}
void hw5q1() {
	const int k = 4;
	cout << "00 ";
	rep(i, k + 1) cout << "0";
	cout << " ";
	rep(i, k + 1) cout << "0";
	cout << "\n";
	cout << "10 ";
	rep(i, k + 1) cout << "0";
	cout << " ";
	rep(i, k + 1) cout << "1";
	cout << "\n";

	rep(i, 1 + (1 << k)) {
		repr(j, 1 << 1) {
			vb a1 = getBinary(j, 2);
			vb a2 = getBinary(i + 1, k);
			for (auto e : a1) cout << e;
			cout << " ";
			bool curr = true;
			for (auto e : a2) curr = curr && e;
			if (curr) cout << "1";
			else cout << "0";
			for (auto e : a2) cout << e;
			cout << " ";
			rep(i, k + 1) cout << "1";
			cout << "\n";
		}
	}
}
void lab5q1() {
	vb a1 = getBinary(32, 8);
	rep(i, 15) for(auto e : a1) cout << e;
}