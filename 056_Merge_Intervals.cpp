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
    static bool cmp(Interval a, Interval b) {
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> mergedIntervals;
        sort(intervals.begin(), intervals.end(),cmp);
        int i = 0;
        int size = intervals.size();
        if(size == 0)
            return mergedIntervals;
        while(i < size) {
            int start = intervals[i].start;
            int end = intervals[i].end;
            i ++;
            while(i < size && intervals[i].start <= end) {
                end = max(end, intervals[i].end);
                i ++;
            }
            Interval newInterval(start, end);
            mergedIntervals.push_back(newInterval);
        }
        return mergedIntervals;
    }
};
