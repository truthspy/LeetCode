class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        while(start < end) {
            if(nums[start] < nums[end])
                return nums[start];
            int mid = start + (end - start) / 2;
            if(nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            if(nums[start] > nums[mid])
                end = mid;
            else
                start = mid + 1;
        }
        return nums[start];
    }
};
