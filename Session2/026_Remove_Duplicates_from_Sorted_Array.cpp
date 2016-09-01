class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        int pos = 1;
        int pre = nums[0];
        for(int i = 1; i < len; i ++) {
            if(nums[i] == pre)
                continue;
            nums[pos] = nums[i];
            pos ++;
            pre = nums[i];
        }
        return pos;
    }
};
