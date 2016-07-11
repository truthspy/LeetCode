//2-pass solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0, 0, 0};
        int size = nums.size();
        for(int i = 0; i < size; i ++)
            count[nums[i]] ++;
        int i = 0;
        while(count[0] > 0) {
            count[0] --;
            nums[i] = 0;
            i ++;
        }
        while(count[1] > 0) {
            count[1] --;
            nums[i] = 1;
            i ++;
        }
        while(count[2] > 0) {
            count[2] --;
            nums[i] = 2;
            i ++;
        }
    }
};

//1-pass solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int zeros = 0;
        int twos = size - 1;
        int i = 0;
        while(i <= twos) { //先换2再换0，保证不会出现把0换到当前位置，然后当前位置还需要换的情况
            while(nums[i] == 2 && i < twos) {
                swap(nums[i], nums[twos]);
                twos --;
            }
            while(nums[i] == 0 && i > zeros) {
                swap(nums[i], nums[zeros]);
                zeros ++;
            }
            i ++;
        }
    }
};
