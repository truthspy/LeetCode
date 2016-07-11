class Solution {
public:
    bool isAdditiveNumber(string num) {
        int size = num.length();
        for(int i = 0; i < size - 2; i ++) {
            if(num[0] == '0' && i > 0)
                return false;
            string subA = num.substr(0, i + 1);
            long long a = stoll(subA);
            for(int j = i + 1; j < size - 1; j ++) {
                if((size - j - 1) < max(i + 1, j - i))
                    break;
                if(num[i + 1] == '0' && j != (i + 1))
                    break;
                string subB = num.substr(i + 1, j - i);
                long long b = stoll(subB);
                if(dfs(num.substr(j + 1), a, b))
                    return true;
            }
        }
        return false;
    }
    bool dfs(string left, long long x1, long long x2) {
        if(left.length() == 0)
            return true;
        long long y = x1 + x2;
        string target = to_string(y);
        int len = target.length();
        if(left.length() < len)
            return false;
        string sub = left.substr(0, len);
        if(sub == target)
            return dfs(left.substr(len), x2, y);
        return false;
    }
};
