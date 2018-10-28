/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> v;
        int N = intervals.size();
        int idx = 0;
        while(idx < N && intervals[idx].end < newInterval.start)
        {
            v.push_back(intervals[idx]);
            idx ++;
        }
        while(idx < N && intervals[idx].start <= newInterval.end )
        {
            newInterval.start = min(intervals[idx].start,newInterval.start);
            newInterval.end = max(newInterval.end,intervals[idx].end);
            idx ++;
        }
        v.push_back(newInterval);
        while(idx < N)
            v.push_back(intervals[idx++]);
        return v;
    }
};
