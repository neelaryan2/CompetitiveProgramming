using ll = long long;
string Solution::fractionToDecimal(int A, int B) {
    string res;
    ll a = A, b = B, sgn = 1;
    if (a < 0) a = -a, sgn *= -1;
    if (b < 0) b = -b, sgn *= -1;
    if (sgn < 0 && a) res += '-';
    res += to_string(a / b), a %= b;
    if (a == 0) return res;
    res += '.', a *= 10;
    map<ll, int> occ;
    string rep; int id = 0;
    while (a && occ.find(a) == occ.end()) {
        occ[a] = id++;
        rep += to_string(a / b);
        a = (a % b) * 10;
    }
    if (a) {
        int l = occ[a];
        res += rep.substr(0, l);
        res += '(' + rep.substr(l, id - l) + ')';
    } else res += rep;
    return res;
}
