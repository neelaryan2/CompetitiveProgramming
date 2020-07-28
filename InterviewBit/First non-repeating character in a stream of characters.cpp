string Solution::solve(string A) {
    queue<int> q;
    string res;
    vector<int> cnt(26, 0);
    for (char c : A) {
        cnt[c - 'a']++;
        q.push(c);
        while (!q.empty() && cnt[q.front() - 'a'] > 1)
            q.pop();
        c = q.empty() ? '#' : q.front();
        res += c;
    }
    return res;
}
