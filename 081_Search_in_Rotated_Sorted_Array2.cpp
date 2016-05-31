/**
 * 先分中间值与最右值的大小比较情况考虑，然后再比较中间值与target的大小情况
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return false;
        return biSearch(nums, target, 0, nums.size() - 1);
    }
    bool biSearch(vector<int>& nums, int target, int l, int r) {
        if(l > r)
            return false;
        int mid = (l + r) / 2;
        if(nums[mid] == target)
            return true;
        if(nums[mid]  < nums[r]) {
            if(nums[mid] < target && nums[r] >= target) //注意判断nums[r]>=target这一条件
                return biSearch(nums, target, mid + 1, r);
            else
                return biSearch(nums, target, l, mid - 1);
        }
        else if(nums[mid] > nums[r]) {
            if(nums[mid] > target && nums[l] <= target)
                return biSearch(nums, target, l, mid - 1);
            else
                return biSearch(nums, target, mid + 1, r);
        }
        else
            return biSearch(nums, target, l, r - 1);    //因为有重复元素出现，所以可能出现(3,1,1)和(1,1,3,1)这种情况，3既可能出现在1左边，也可能出现在1右边
    }
};
