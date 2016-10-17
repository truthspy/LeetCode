class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for(int i = 1; i < n; i ++)
            left[i] = left[i - 1] * nums[i - 1];
        res[n - 1] = left[n - 1];
        for(int i = n - 2; i >= 0; i --) {
            right[i] = right[i + 1] * nums[i + 1];
            res[i] = left[i] * right[i]; //可以直接合在一个循环里
        }
        // for(int i = 0; i < n; i ++)
        //     res[i] = left[i] * right[i];
        return res;
    }
};
