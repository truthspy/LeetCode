class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        for(int i = 0; i <= r; i ++) {
            if(nums[i] == 0) {
                swap(nums[i], nums[l]);
                l ++;
            }
            else if(nums[i] == 2) {
                swap(nums[i], nums[r]);
                i --;
                r --;
            }
        }
    }
};
