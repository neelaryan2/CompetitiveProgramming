bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    int n = arrive.size();
    for (int i = K; i < n; i++)
        if (depart[i - K] > arrive[i])
            return false;
    return true;
}
