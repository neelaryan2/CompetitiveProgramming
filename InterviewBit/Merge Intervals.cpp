/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    auto cmp = [](Interval& a, Interval& b) { return a.start < b.start; };
    sort(intervals.begin(), intervals.end(), cmp);
    if (newInterval.end < newInterval.start) 
        swap(newInterval.start, newInterval.end);
    vector<Interval> ans;
    bool pushed = false;
    for (int i = 0; i < intervals.size(); i++) {
        if (newInterval.start > intervals[i].end) {
            ans.push_back(intervals[i]);
        } else if (newInterval.end < intervals[i].start) {
            if (!pushed) {
                ans.push_back(newInterval);
                pushed = true;
            }
            ans.push_back(intervals[i]);
        } else {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
        }
    }
    if (!pushed) {
        ans.push_back(newInterval);
        pushed = true;
    }
    return ans;
}
