//O(n) 太复杂
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) 
            return 0;
        for(int i = 0; i < size; i ++) {
            if(i == 0 && nums[i] > nums[i + 1])
                return i;
            if(i == size - 1 && nums[i] > nums[i - 1])
                return i;
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                return i;
        }
        return 0;
    }
};

// 代码简单，O(n)
/**
 * 只要从左向右遍历，如果比前一个数大，继续
 * 如果比前一个数小，那么前一个数比它的前一个大，又比当前大，是peak
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        for(int i = 1; i < size; i ++) {
            if(nums[i] < nums[i - 1])
                return i - 1;
        }
        return size - 1;
    }
};

//二分,O(lgn)
/**
 * 二分实现
 * 如果mid比mid+1大，那么[start,mid]一定有peak
 * 否则，[mid+1,end]一定有peak
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        int start = 0;
        int end = size - 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] > nums[mid + 1])
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }
};
