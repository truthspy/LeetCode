class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid] < nums[mid + 1])
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
///太复杂
/*
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        if(r == 0)
            return 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(mid == 0) {
                if(nums[mid] > nums[mid + 1])
                    return mid;
                else {
                    l = mid + 1;
                    continue;
                }
            }
            if(mid == nums.size() - 1) {
                if(nums[mid] > nums[mid - 1])
                    return mid;
                else {
                    r = mid - 1;
                    continue;
                }
            }
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if(nums[mid] < nums[mid - 1])
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};
*/
