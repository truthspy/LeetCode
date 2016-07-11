/*
思路：
对所有数进行异或操作
所有出现两次的数异或之后结果为0
一个数和0异或结果是它本身
所以最后的结果就是只出现一次的数
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        int size = nums.size();
        for(int i = 0; i < size; i ++) {
            result = result ^ nums[i];
        }
        return result;
    }
};
