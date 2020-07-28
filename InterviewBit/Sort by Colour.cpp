void Solution::sortColors(vector<int> &A) {
    vector<int> cnt(3, 0);
    for (int i : A) cnt[i]++;
    for (int i = 0, p = 0; i < 3; i++)
        while (cnt[i]--)
            A[p++] = i;
}
