// 通过右移判断，用count记录有几个10开头的
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        int count = 0;
        for(int i = 0; i < n; i ++) {
            if(count == 0) {
                if((data[i] >> 7) == 0)
                    continue;
                else if((data[i] >> 5) == 0b110)
                    count = 1;
                else if((data[i] >> 4) == 0b1110)
                    count = 2;
                else if((data[i] >> 3) == 0b11110)
                    count = 3;
                else
                    return false;
            }
            else {
                if((data[i] >> 6) == 0b10)
                    count --;
                else 
                    return false;
            }
        }
        return count == 0;
    }
};
