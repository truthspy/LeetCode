// 这是O(n)space的解法
// 还有O(1)space的解法，类似linked list环的检测，用两个快慢指针，fast每次调用两步，直到两个指针相遇或者为1
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> happys;
        if(n <= 0)
            return false;
        happys.insert(n);
        while(n != 1) {
            int cur = 0;
            while(n != 0) {
                int dig = n % 10;
                cur += (dig * dig);
                n = n / 10;
            }
            n = cur;
            if(happys.find(n) != happys.end())
                return false;
            happys.insert(n);
        }
        return true;
    }
};
