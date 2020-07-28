using ld = long double;
const ld inf = INT_MAX;
using arr = array<ld, 3>;
arr getMax(vector<ld> a) {
    arr mx = {-inf, -inf, -inf};
    for (ld e : a) {
        if (e > mx[0]) {
            mx[2] = mx[1];
            mx[1] = mx[0];
            mx[0] = e;
        } else if (e > mx[1]) {
            mx[2] = mx[1];
            mx[1] = e;
        } else if (e > mx[2]) {
            mx[2] = e;
        }
    }
    return mx;
}
arr getMin(vector<ld> a) {
    arr mn = {inf, inf, inf};
    for (ld e : a) {
        if (e < mn[0]) {
            mn[2] = mn[1];
            mn[1] = mn[0];
            mn[0] = e;
        } else if (e < mn[1]) {
            mn[2] = mn[1];
            mn[1] = e;
        } else if (e < mn[2]) {
            mn[2] = e;
        }
    }
    return mn;
}
int Solution::solve(vector<string> &A) {
    vector<ld> x, y, z;
    for (string& s : A) {
        ld c = stod(s);
        if (c < 2.0 / 3) x.push_back(c);
        else if (c <= 1.0) y.push_back(c);
        else if (c < 2.0) z.push_back(c);
    }
    int sx = x.size(), sy = y.size(), sz = z.size();
    arr mxx = getMax(x), mnx = getMin(x);
    arr mxy = getMax(y), mny = getMin(y);
    arr mxz = getMax(z), mnz = getMin(z);
    if (sx >= 3 && mxx[0] + mxx[1] + mxx[2] > 1.0) return 1;
    if (sx >= 2 && sz >= 1 && mnx[0] + mnx[1] + mnz[0] < 2.0) return 1;
    if (sx >= 1 && sy >= 2 && mnx[0] + mny[0] + mny[1] < 2.0) return 1;
    if (sx >= 1 && sy >= 1 && sz >= 1 && mnx[0] + mny[0] + mnz[0] < 2) return 1;
    vector<ld> x1, x2;
    for (ld xx : x) {
        if (xx < 1.0 / 2) x1.push_back(xx);
        else x2.push_back(xx);
    }
    int sx1 = x1.size(), sx2 = x2.size();
    arr mxx1 = getMax(x1), mnx1 = getMin(x1);
    arr mxx2 = getMax(x2), mnx2 = getMin(x2);
    if (sx1 >= 1 && sx2 >= 1 && sy >= 1 && mnx1[0] + mnx2[0] + mny[0] < 2.0) return 1;
    if (sx2 >= 2 && sy >= 1 && mnx2[0] + mnx2[1] + mny[0] < 2.0) return 1;
    if (sx1 >= 2 && sy >= 1 && mxx1[0] + mxx1[1] + mxy[0] > 1.0) return 1;
    return 0;
}
