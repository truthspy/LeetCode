// Divide & Conquer
// max = max(左边的最大，右边的最大，通过mid point的最大)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        if(r == 0)
            return nums[0];
        return getMax(l, r, nums);
    }
    int getMax(int l, int r, vector<int>& nums) {
        if(l == r)
            return nums[l];
        int mid = (l + r) / 2;
        int leftMax = getMax(l, mid, nums);
        int rightMax = getMax(mid + 1, r, nums);
        int totalMax = nums[mid];
        int totalCur = nums[mid];
        for(int i = mid - 1; i >= l; i --) {
            totalCur += nums[i];
            totalMax = max(totalMax, totalCur);
        }
        totalCur = totalMax;
        for(int i = mid + 1; i <= r; i ++) {
            totalCur += nums[i];
            totalMax = max(totalMax, totalCur);
        }
        return max(totalMax, max(leftMax, rightMax));
    }
};
// DP O(n) solution
/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> curMax(size);
        curMax[0] = nums[0];
        int res = curMax[0];
        for(int i = 1; i < size; i ++) {
            curMax[i] = max(curMax[i - 1] + nums[i], nums[i]);
            res = max(res, curMax[i]);
        }
        return res;
    }
};
*/
