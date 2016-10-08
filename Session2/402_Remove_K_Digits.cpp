// TODO
// 看了答案
// 第i位的数字如果比第i-1位的小，那么如果只能移除一个的话，则移除i-1位
// 所以从头到尾，如果第i位比之前数组里最后一个小，移除最后一个，重复，直到第i位比数组最后一个大位置
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        int len = num.size();
        for(int i = 0; i < len; i ++) {
            while(k > 0 && !s.empty() && num[i] < s.top()) {
                s.pop();
                k --;
            }
            s.push(num[i]);
        }
        while(k > 0 && !s.empty()) {
            k --;
            s.pop();
        }
        string res = "";
        while(!s.empty()) {
            res += s.top();
            s.pop();
        }
        while(res.back() == '0')
            res.pop_back();
        reverse(res.begin(), res.end());
        if(res == "")
            res = "0";
        return res;
    }
};
