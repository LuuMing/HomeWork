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
   static bool cmp(const Interval & i1, const Interval & i2)
    {
        return i1.start == i2.start ? i1.end < i2.end: i1.start < i2.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty()) return {};
        sort(intervals.begin(),intervals.end(),cmp);
        vector<Interval> result;
        Interval  s = intervals[0];
        for(int i = 1; i < intervals.size(); i++)
        {
            if( s.end >= intervals[i].start )
            {
                s.end = max(s.end,intervals[i].end);
            }
            else
            {
                result.push_back(s);
                s = intervals[i];
            }
        }
        result.push_back(s);
        return result;
    }
};
