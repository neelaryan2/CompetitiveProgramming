#include<bits/stdc++.h>
using namespace std;
const double inf = 1e13;

struct line {
	double a, b, c;
};
struct point {
	double x, y;
};
struct node {
	node *l, *r;
	int num_left, num_right;
	line lin;
	node(line li) {
		this->l = this->r = NULL;
		this->num_left = this->num_right = 0;
		this->lin = li;
	}
};
vector<int> counts;
int num_regions, height;

point inter(line a1, line a2) {
	double d = (a1.a * a2.b - a1.b * a2.a);
	double a = (a2.b * a1.c - a1.b * a2.c);
	double b = (a1.a * a2.c - a2.a * a1.c);
	point t;
	if (d) t.x = a / d, t.y = b / d;
	return t;
}
double value(line li, point k) {
	return li.a * k.x + li.b * k.y - li.c;
}
node* insert(line li, point k1, point k2, node* v) {
	if (v == NULL) {
		v = new node(li);
		return v;
	}
	double t1 = value(v->lin, k1) , t2 = value(v->lin, k2);
	if (t1 * t2 < 0) {
		point p = inter(li, v->lin);
		if (t1 > 0 && t2 < 0) {
			v->l = insert(li, k2, p, v->l);
			v->r = insert(li, p, k1, v->r);
		}
		else {
			v->l = insert(li, k1, p, v->l);
			v->r = insert(li, p, k2, v->r);
		}
	}
	else {
		if (t1 >= 0) v->r = insert(li, k1, k2, v->r);
		else v->l = insert(li, k1, k2, v->l);
	}
	return v;
}
void adder(node * v, point p) {
	double t = value(v->lin, p);
	if (t == 0) return;
	if (t > 0) {
		if (v->r == NULL) v->num_right++; 
		else adder(v->r, p);
	}
	else {
		if (v->l == NULL) v->num_left++; 
		else adder(v->l, p);
	}
}
int dfs(node * v) {
	if (v == NULL)
		return 0;
	if (v->l == NULL)
		counts[v->num_left]++, num_regions++;
	if (v->r == NULL)
		counts[v->num_right]++, num_regions++;
	return 1 + max(dfs(v->r),	dfs(v->l));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	line temp;
	point k1, k2;
	if (n) {
		cin >> temp.a >> temp.b >> temp.c;
		node* root = new node(temp);
		for (int i = 1; i < n; i++) {
			cin >> temp.a >> temp.b >> temp.c;
			if (temp.a == 0 && temp.b == 0)
				continue;
			if (temp.b == 0) {
				k1.x = k2.x = temp.c / temp.a;
				k1.y = -inf, k2.y = inf;
			}
			else if (temp.a == 0) {
				k1.y = k2.y = temp.c / temp.b;
				k1.x = -inf, k2.x = inf;
			}
			else {
				k1.x = -inf, k2.x = inf;
				k1.y = (temp.c - temp.a * k1.x) / temp.b;
				k2.y = (temp.c - temp.a * k2.x) / temp.b;
			}
			insert(temp, k1, k2, root);
		}
		for (int i = 0; i < m; i++) {
			cin >> k1.x >> k1.y;
			counts.push_back(-1);
			adder(root, k1);
		}
		counts.push_back(-1);
		height = dfs(root);
		cout << num_regions << " " << height << endl;
		for (int i = 0; i <= m; i++)
			if (counts[i] != -1)
				cout << i << " " << ++counts[i] << endl;
	}
	else {
		cout << 1 << " " << 0 << endl;
		cout << m << " " << 1 << endl;
	}
}