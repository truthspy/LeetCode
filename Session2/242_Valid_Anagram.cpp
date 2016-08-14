// 全部小写字母，可以不用map，直接数组搞定
class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        if(len1 != len2)
            return false;
        unordered_map<char,int> mp;
        // 长度一样，保证不会出现最后不是0的情况，不需要count
        // int count = 0;
        for(int i = 0; i < len1; i ++) {
            // if(mp.find(s[i]) == mp.end())
            //     count ++;
            mp[s[i]] ++;
        }
        for(int i = 0; i < len2; i ++) {
            if(mp.find(t[i]) == mp.end())
                return false;
            if(mp[t[i]] == 0)
                return false;
            mp[t[i]] --;
            // if(mp[t[i]] == 0)
            //     count --;
        }
        // return (count == 0);
        return true;
    }
};
// follow-up: unicode characters
