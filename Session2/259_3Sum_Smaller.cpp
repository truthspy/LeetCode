class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n - 2; i ++) {
            int l = i + 1;
            int r = n - 1;
            while(l < r) {
                int sum = nums[l] + nums[r] + nums[i];
                if(sum < target) {
                    count += (r - l);
                    l ++;
                }
                else
                    r --;
            }
        }
        return count;
    }
};
