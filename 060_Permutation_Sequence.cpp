/**
 * 思路：http://www.cnblogs.com/grandyang/p/4358678.html
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        vector<int> fraction(n, 1);
        for(int i = 1; i < n; i ++) {
            fraction[i] = fraction[i - 1] * i;
            nums.push_back(i);
        }
        string result = "";
        k --;       //要转换成数组下标！！
        nums.push_back(n);
        while(n > 0) {
            int i = k / fraction[n - 1];
            k = k % fraction[n - 1];
            result += ('0' + nums[i]);
            nums.erase(nums.begin() + i);
            n --;
        }
        return result;
    }
};
