//更快的方法：找到非0位置交换
//TODO 再理解一下
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int pos = 0;
        for(int i = 0; i < size; i ++) {
            if(nums[i] != 0) {
                swap(nums[pos], nums[i]);
                pos ++;
            }
        }
    }
};

/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int pos = 0;
        for(int i = 0; i < size; i ++) {
            if(nums[i] != 0) {
                nums[pos] = nums[i];
                pos ++;
            }
        }
        while(pos < size) {
            nums[pos] = 0;
            pos ++;
        }
    }
};
*/
