/**
 * 不能改变原数组，所以不能用排序做
 * Method1: O(nlogn)
 * 看了http://www.cnblogs.com/grandyang/p/4843654.html
 * 对于[1,n]二分搜索
 * 如果小于等于mid数字个数大于mid，则重复数字出现在[1,mid]中，否则出现在[mid + 1, n]中
 * 要分清这里l/r/mid是出现的数字，不是下标，不能混
 * TODO
 * Method2：O(n)
 * https://leetcode.com/discuss/61514/understood-solution-space-without-modifying-explanation
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1;
        int r = nums.size() - 1;
        while(l < r) {
            int mid = (l + r) / 2;
            int count = 0;
            for(int i = 0; i < nums.size(); i ++) {
                if(nums[i] <= mid)
                    count ++;
            }
            if(count > mid)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
