class Solution {
public:
    string countAndSay(int n) {
        string cur = "1";
        string next = "";
        while(n > 1) {
            n --;
            next = "";
            int count = 1;
            char pre = cur[0];
            for(int i = 1; i < cur.size(); i ++) {
                if(cur[i] == pre) {
                    count ++;
                    continue;
                }
                else {
                    next += (to_string(count) + pre);
                    pre = cur[i];
                    count = 1;
                }
            }
            next += (to_string(count) + pre);
            cur = next;
        }
        return cur;
    }
};
