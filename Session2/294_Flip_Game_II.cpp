// 博弈类问题，递归+记录，记得要回溯！！
class Solution {
private:
    unordered_map<string, bool> mp;
public:
    bool canWin(string s) {
        if(mp.find(s) != mp.end())
            return mp[s];
        for(int i = 1; i < s.length(); i ++) {
            if(s[i - 1] == '+' && s[i] == '+') {
                s[i - 1] = '-';
                s[i] = '-';
                bool nextCan = !canWin(s);
                s[i - 1] = '+';
                s[i] = '+';
                if(nextCan) {
                    mp[s] = true;
                    return true;
                }
            }
        }
        mp[s] = false;
        return false;
    }
};
