class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int len = 0;
        int count = 0;
        int pre;
        for(int i = 0; i < size; i ++) {
            if(count == 0) {
                pre = nums[i];
                nums[len] = nums[i];
                len ++;
                count ++;
            }
            else if(nums[i] == pre) {
                if(count < 2) {
                    nums[len] = nums[i];
                    len ++;
                    count ++;
                }
            }
            else {
                pre = nums[i];
                count = 1;
                nums[len] = nums[i];
                len ++;
            }
        }
        return len;
    }
};
