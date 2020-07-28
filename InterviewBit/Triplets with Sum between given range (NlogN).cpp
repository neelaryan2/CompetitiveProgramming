using ld = long double;
#define all(v) (v).begin(), (v).end()
#define lb lower_bound
#define ub upper_bound
inline ld num(string &s) {
    ld x = 0, y = 1.0 / 10;
    bool found = 0;
    for (char &c : s) {
        if (c == '.') {
            found = 1; 
            continue;
        }
        if (found) {
            x += y * (c - '0');
            y /= 10;
        } else {
            x *= 10;
            x += (c - '0');
        }
    }
    return x;
}
int Solution::solve(vector<string> &A) {
    int n = A.size();
    vector<ld> a(n);
    for (size_t i = 0; i < n; i++)
        a[i] = num(A[i]);
    sort(all(a));
    int l = ub(all(a), 1.0 / 3) - a.begin();
    int k = lb(all(a), 2.0 / 3) - a.begin();
    int i = lb(all(a), 1.0) - a.begin();
    int n1, n2, n3; // 0 < x <= 1/3, 1/3 < x < 2/3, 2/3 <= x < 1
    n1 = l; n2 = k - l; n3 = i - k;
    if (n2 >= 3) 
        return true;
    if (n1 > 0 && n2 > 0 && n3 > 0) 
        return true;
    if (i >= 2 && i < n)
        if (a[0] + a[1] + a[i] < 2.0) 
            return true;
    if (k >= 1 && n3 > 1)
        if (a[0] + a[k] + a[k + 1] < 2.0) 
            return true;
    if (n2 >= 2 && n3 >= 1)
        if (a[l] + a[l + 1] + a[k] < 2.0) 
            return true;
    if (n1 >= 2 && n3 >= 1)
        if (a[l - 1] + a[l - 2] + a[i - 1] > 1.0) 
            return true;
    if (n1 + n2 >= 3)
        if (a[k - 1] + a[k - 2] + a[k - 3] > 1.0) 
            return true;
    return false;
}