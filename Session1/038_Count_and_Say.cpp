class Solution {
public:
    string countAndSay(int n) {
        string pre = "1";
        string cur = pre;
        int i = 1;
        while(i < n) {
            i ++;
            int len = pre.length();
            cur = "";
            int count = 1;
            char last = pre[0];
            for(int j = 1; j < len; j ++) {
                if(pre[j] == last)
                    count ++;
                else {
                    cur += (to_string(count) + last);
                    count = 1;
                    last = pre[j];
                }
            }
            cur += (to_string(count) + last);
            pre = cur;
        }
        return cur;
    }
};
