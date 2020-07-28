int Solution::solve(int A) {
    int cnt = 0;
    while (A && A % 2 == 0) A /= 2, cnt++;
    return cnt;
}
