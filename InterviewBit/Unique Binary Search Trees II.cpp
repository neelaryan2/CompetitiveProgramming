vector<int> memo(20, -1);
int Solution::numTrees(int A) {
    if (memo[A] != -1) return memo[A];
    if (A <= 1) return memo[A] = 1;
    int ans = 0;
    for (int i = 0; i < A; i++)
        ans += numTrees(i) * numTrees(A - i - 1);
    return memo[A] = ans;
}
