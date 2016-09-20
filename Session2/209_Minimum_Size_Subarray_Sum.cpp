// TODO nlgn
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int size = nums.size();
        int sum = 0;
        int res = size + 1;
        for(r = 0; r < size; r ++) {
            sum += nums[r];
            while(sum >= s) {
                res = min(r - l + 1, res);
                sum -= nums[l];
                l ++;
            }
        }
        if(res == size + 1)
            return 0;
        return res;
    }
};
