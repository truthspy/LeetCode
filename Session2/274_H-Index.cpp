// @TODO 再看！！
// 从discuss看来的。。。
// 也可以先从大到小排序，然后类似方法，不过是O(nlogn)的
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n + 1, 0);
        for(int i = 0; i < n; i ++) {
            if(citations[i] >= n)
                count[n] ++;
            else
                count[citations[i]] ++;
        }
        int sum = 0;
        for(int i = n; i >= 0; i --) {
            sum += count[i];
            if(sum >= i)
                return i;
        }
        return -1;
    }
};
