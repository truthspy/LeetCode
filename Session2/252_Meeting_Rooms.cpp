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
    bool canAttendMeetings(vector<Interval>& intervals) {
        int size = intervals.size();
        sort(intervals.begin(), intervals.end(), mycmp);
        for(int i = 1; i < size; i ++) {
            if(intervals[i].start < intervals[i - 1].end)
                return false;
        }
        return true;
    }
    static bool mycmp(Interval A, Interval B) {
        return A.start < B.start;
    }
};
