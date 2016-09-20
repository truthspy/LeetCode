class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int len = s.length();
        int l = 0;
        int res = 0;
        int count = 0;
        unordered_map<char, int> mp;
        for(int i = 0; i < len; i ++) {
            if(mp[s[i]] == 0)
                count ++;
            mp[s[i]] ++;
            while(count > k) {
                mp[s[l]] --;
                if(mp[s[l]] == 0)
                    count --;
                l ++;
            }
            res = max(i - l + 1, res);
        }
        return res;
    }
};
