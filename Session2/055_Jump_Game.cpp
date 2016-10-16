class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int fareast = 0;
        for(int i = 0; i < n; i ++) {
            if(i > fareast)
                return false;
            fareast = max(fareast, i + nums[i]);
        }
        return true;
    }
};
