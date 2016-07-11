/**
 * 我的思路（没写）：桶排序，高位优先 or 重载排序算法--从高位开始比较，高位值大的比较大，如果前几位一样，则短的比较大
 * 看了http://www.cnblogs.com/grandyang/p/4539768.html
 * 另一种重载排序方法：对于两个数字a和b来说，如果将其都转为字符串，如果ab > ba，则a排在前面，
 * 比如9和34，由于934>349，所以9排在前面，再比如说30和3，由于303<330，所以3排在30的前面
 * 写了这种
 */
bool mysort(int a, int b) {
    string ab = to_string(a) + to_string(b);
    string ba = to_string(b) + to_string(a);
    return ab > ba;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return "0";
        sort(nums.begin(), nums.end(), mysort);
        string result = "";
        for(int i = 0; i < size; i ++)
            result += to_string(nums[i]);
        if(result[0] == '0')
            result = "0";       //test case: [0, 0]，没有这个判断的话输出“00”
        return result;
    }
};
