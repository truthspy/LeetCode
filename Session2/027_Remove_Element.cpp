class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r) {
            if(nums[l] != val) {
                l ++;
                continue;
            }
            nums[l] = nums[r];
            r --;
        }
        return l;
    }
};
