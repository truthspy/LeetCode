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
    static bool mycmp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<int, vector<int>, greater<int>> endTime;
        sort(intervals.begin(), intervals.end(), mycmp);
        int n = intervals.size();
        int count = 0;
        for(int i = 0; i < n; i ++) {
            if(endTime.empty() || intervals[i].start < endTime.top()) {
                endTime.push(intervals[i].end);
                count ++;
            }
            else {
                endTime.pop();
                endTime.push(intervals[i].end);
            }
        }
        return count;
    }
};
