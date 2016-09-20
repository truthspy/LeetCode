// TODO
// Method only for k = 2, and the space is O(1)
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int len = s.length();
        unordered_map<char, int> mp;
        int count = 0;
        int res = 0;
        int l = 0;
        for(int i = 0; i < len; i ++) {
            // cannot use mp.find(s[i]) == mp.end()
            // because s[i] may appear before and we don't erase it from the map
            if(mp[s[i]] == 0) {
                mp[s[i]] ++;
                count ++;
            }
            else
                mp[s[i]] ++;
            while(count > 2) {
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
