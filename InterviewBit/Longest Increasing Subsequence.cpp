int Solution::lis(const vector<int> &A) {
    multiset<int> s;
    for (int e : A) {
        s.insert(e);
        auto it = s.lower_bound(e);
        if (++it != s.end()) s.erase(it);
    }
    return s.size();
}
