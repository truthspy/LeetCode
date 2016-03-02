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
        vector<Interval> result;
        int size = intervals.size();
        int i = 0;
        while(i < size && newInterval.start > intervals[i].end) {
            result.push_back(intervals[i]);
            i ++;
        }
        if(i == size) {
            result.push_back(newInterval);
            return result;
        }
        if(newInterval.end < intervals[i].start) {
            result.push_back(newInterval);
        }
        else {
            newInterval.start = min(intervals[i].start, newInterval.start);
            newInterval.end = max(intervals[i].end, newInterval.end);
            i ++;
            while(i < size && intervals[i].start <= newInterval.end) {
                newInterval.end = max(newInterval.end, intervals[i].end);
                i ++;
            }
            result.push_back(newInterval);
        }
        while(i < size) {
            result.push_back(intervals[i]);
            i ++;
        }
        return result;
    }
};
