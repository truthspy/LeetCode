class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int len = nums.size();
        for(int i = 0; i < len; i ++) {
            if(i == 0)
                result.push_back(1);
            else
                result.push_back(result[i - 1] * nums[i - 1]);
        }
        int curProduct = 1;
        for(int i = len - 1; i >= 0; i --) {
            result[i] *= curProduct;
            curProduct *= nums[i];
        }
        return result;
    }
};
