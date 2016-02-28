/**
 * 思路from discuss
 * 只出现一次的两个数必定有pos位，一个为0，一个为1
 * 通过pos位为0还是1，将数据分成两组，这两个数分别在一组中，而且这两组中的其他数都在该组中出现两次
 * 分别对这两组数异或，即可以获取到这两个数
 * pos值的获取可以通过将所有数异或，结果中不为0的位即为pos
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int size = nums.size();
        vector<int> result;
        int diff = 0;
        for(int i = 0; i < size; i ++) {
            diff = (diff ^ nums[i]);
        }
        int pos = 0;
        while((diff & 1) == 0) {
            diff = (diff >> 1);
            pos ++;
        }
        int result0 = 0;
        int result1 = 0;
        for(int i = 0; i < size; i ++) {
            if((nums[i] >> pos) & 1)
                result1 = (result1 ^ nums[i]);
            else
                result0 = (result0 ^ nums[i]);
        }
        result.push_back(result0);
        result.push_back(result1);
        return result;
    }
};
