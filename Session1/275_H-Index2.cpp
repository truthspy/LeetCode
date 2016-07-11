/**
 * http://blog.csdn.net/yeruby/article/details/49871329
 * discuss的解法
 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        int start = 0;
        int end = size - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(citations[mid] == (size - mid))
                return citations[mid];
            if(citations[mid] > (size - mid))
                end = mid - 1;
            else
                start = mid + 1;
        }
        return size - start;
    }
};
