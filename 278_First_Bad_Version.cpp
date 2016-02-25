// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

/*
要搞清楚边界条件！！！
*/
class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(isBadVersion(mid)) {
                end = mid;
            }
            else
                start = mid + 1;
        }
        return start;
    }
};
