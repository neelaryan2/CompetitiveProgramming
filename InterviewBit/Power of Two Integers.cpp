int Solution::isPower(int A) {
    if (A == 1) return true;
    for (int i = 2; i * i <= A; i++) {
        int res = i, up = A / i;
        while (true) {
            if (res > up) break;
            res = res * i;
            if (res == A) return true;
        }
    }
    return false;
}
