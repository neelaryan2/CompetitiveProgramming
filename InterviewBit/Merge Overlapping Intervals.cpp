/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::merge(vector<Interval> &A) {
    auto cmp = [&](Interval& a, Interval& b) { return a.start < b.start; };
    sort(A.begin(), A.end(), cmp);
    Interval seg = A[0];
    vector<Interval> ans;
    for (int i = 1; i < A.size(); i++) {
        if (A[i].start <= seg.end)
            seg.end = max(seg.end, A[i].end);
        else {
            ans.push_back(seg);
            seg = A[i];
        }
    }
    ans.push_back(seg);
    return ans;
}