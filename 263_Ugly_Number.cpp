class Solution {
public:
    bool isUgly(int num) {
        
        // 判断等于0的情况！！！！！否则死循环
        if(num <= 0) 
            return false;
            
        while(num % 5 == 0)
            num = num / 5;
        while(num % 3 == 0)
            num = num / 3;
        while(num % 2 == 0)
            num = num / 2;
        return (num == 1);
    }
};
