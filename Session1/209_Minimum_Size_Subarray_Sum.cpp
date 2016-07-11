/**
 * O(n) Solution
 * 滑动窗口方法
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int result = size + 1;
        while(l < size && r < size) {
            sum += nums[r];
            while(l <= r && sum >= s) {
                result = min(result, r - l + 1);
                sum = sum - nums[l];
                l ++;
            }
            r ++;
        }
        if(result == size + 1)
            result = 0;
        return result;
    }
};
/**
* TODO
* O(nlogn) Solution
*/
