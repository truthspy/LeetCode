class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool neg = false;
        if((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0))
            neg = true;
        long long a = abs((long long)numerator);
        long long b = abs((long long)denominator);
        long long cur = a / b;
        long long fraction = a % b;
        string res = to_string(cur);
        if(neg && (cur > 0 || fraction > 0))
            res = "-" + res;
        if(fraction == 0)
            return res;
        res += ".";
        string right = "";
        int pos = 0;
        unordered_map<long long, int> mp;
        while(fraction != 0) {
            if(mp.find(fraction) != mp.end()) {
                right.insert(mp[fraction], "(");
                right += ")";
                break;
            }
            mp[fraction] = pos;
            fraction *= 10;
            right += to_string(fraction / b);
            fraction =  fraction % b;
            pos ++;
        }
        return res + right;
    }
};
