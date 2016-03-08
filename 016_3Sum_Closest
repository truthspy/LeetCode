class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minGap = INT_MAX;
        int result = 0;
        for(int i = 0; i < nums.size() - 2; i ++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k) {
                int total = nums[i] + nums[j] + nums[k];
                int gap = abs(total - target);
                if(gap < minGap) {
                    minGap = gap;
                    result = total;
                }
                if(total == target)
                    return target;
                else if(total > target)
                    k --;
                else
                    j ++;
            }
        }
        return result;
    }
};
