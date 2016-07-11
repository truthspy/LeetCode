/**
 * 还是看了discuss的。。。
 * 思考总结：rotate带duplicates的情况，如果碰到相等，那么直接将left/right向后或者向前移1，继续查找即可。
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right])
                left = mid + 1;
            else if(nums[mid] < nums[right])
                right = mid;
            else
                right --;
        }
        return nums[left];
    }
};
