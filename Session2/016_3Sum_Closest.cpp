class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        int minDiff = INT_MAX;
        for(int i = 0; i < n - 2; i ++) {
            int curTarget = target - nums[i];
            int l = i + 1;
            int r = n - 1;
            while(l < r) {
                int sum = nums[l] + nums[r];
                if(sum == curTarget)
                    return target;
                if(sum > curTarget) {
                    if(sum - curTarget < minDiff) {
                        minDiff = sum - curTarget;
                        res = sum + nums[i];
                    }
                    r --;
                }
                else {
                    if(curTarget - sum < minDiff) {
                        minDiff = curTarget - sum;
                        res = sum + nums[i];
                    }
                    l ++;
                }
            }
        }
        return res;
    }
};
