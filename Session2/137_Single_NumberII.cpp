class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[32] = {0};
        for(int i = 0; i < nums.size(); i ++) {
            int cur = 0;
            while(nums[i] != 0 && cur < 32) {
                count[cur] += (nums[i] & 1);
                cur ++;
                nums[i] = nums[i] >> 1;
            }
        }
        int res = 0;
        for(int i = 31; i >= 0; i --){
            count[i] = count[i] % 3;
            res = res * 2 + count[i];
        }
        return res;
    }
};
