class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(target == nums[mid])
                return mid;
            if(target < nums[mid]) {
                if(nums[l] <= nums[mid] && nums[l] > target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else {
                if(nums[r] >= nums[mid] && nums[r] < target)
                    r = mid - 1;
                else 
                    l = mid + 1;
            }
        }
        return -1;
    }
};
