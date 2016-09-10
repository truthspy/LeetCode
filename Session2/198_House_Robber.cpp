class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        if(size == 1)
            return nums[0];
        vector<int> money(size, 0);
        money[0] = nums[0];
        money[1] = max(money[0], nums[1]);
        for(int i = 2; i < size; i ++) {
            money[i] = max(money[i - 2] + nums[i], money[i - 1]);
        }
        return money[size - 1];
    }
};
