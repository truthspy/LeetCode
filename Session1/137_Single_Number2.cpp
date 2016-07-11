/**
 * 思路from solution-cpp.pdf
 * 用count数组记录第i位1出现了几次
 * count[i] % 3即为待求的数该位的值
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bitLen = sizeof(int) * 8;
        int size = nums.size();
        vector<int> count(bitLen, 0);
        for(int i = 0; i < size; i ++) {
            for(int j = 0; j < bitLen; j ++) {
                count[j] += ((nums[i] >> j) & 1);
            }
        }
        int result = 0;
        for(int i = 0; i < bitLen; i ++) {
            count[i] = count[i] % 3;
            result = result + (count[i] << i);
        }
        return result;
    }
};
