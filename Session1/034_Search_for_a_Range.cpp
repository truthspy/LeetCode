class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> result(2, -1);
        if(size == 0)
            return result;
        findRange(nums, result, target, 0, size - 1);
        return result;
    }
    void findRange(vector<int>& nums, vector<int>& result, int target, int start, int end) {
        if(start > end)
            return;
        int mid = (start + end) / 2;
        if(nums[mid] > target) {
            findRange(nums, result, target, start, mid - 1);
        }
        else if(nums[mid] < target)
            findRange(nums, result, target, mid + 1, end);
        else {
            if(result[0] == -1) {
                result[0] = mid;
                result[1] = mid;
                findRange(nums, result, target, start, mid - 1);
                findRange(nums, result, target, mid + 1, end);
            }
            else if(mid < result[0]) {
                result[0] = mid;
                findRange(nums, result, target, start, mid - 1);
            }
            else {
                result[1] = mid;
                findRange(nums, result, target, mid + 1, end);
            }
        }
    }
};

//还可以分两步，先二分找最左端，再二分找最右端
