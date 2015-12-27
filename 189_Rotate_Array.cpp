class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> tmp;
        int i = n - k;
        while(i < n) {
            tmp.push_back(nums[i]);
            i ++;
        }
        i --;
        while(i >= k) {
            nums[i] = nums[i - k];
            i --;
        }
        for(i = 0; i < k; i ++) {
            nums[i] = tmp[i];
        }
    }
};
