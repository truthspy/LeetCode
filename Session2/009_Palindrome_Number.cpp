// 可以直接通过比较数的大小来判断是不是到中点，不需要先计算长度
class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0)
            return true;
        // 注意！需要排除能被10整除的情况！
        if(x < 0 || x % 10 == 0)
            return false;
        int half = 0;
        while(x > half) {
            half = half * 10 + x % 10;
            x = x / 10;
        }
        return (x == half) || (x == half / 10);
    }
};
/*
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x == 0)
            return true;
        int cur = x;
        int len = 0;
        while(cur != 0) {
            len ++;
            cur = cur / 10;
        }
        int half = len / 2;
        int pre = len - half;
        int res = 0;
        while(half > 0) {
            res = res * 10 + (x % 10);
            x = x / 10;
            half --;
            pre --;
        }
        if(pre > 0)
            x = x / 10;
        return x == res;
    }
};
*/
