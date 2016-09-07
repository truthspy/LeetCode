class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length();
        vector<int> mp(256, -1);
        int start = 0;
        int maxLen = 0;
        for(int i = 0; i < size; i ++) {
            if(mp[s[i]] < start) {
                mp[s[i]] = i;
            }
            else {
                maxLen = max(maxLen, i - start);
                start = mp[s[i]] + 1;
                mp[s[i]] = i;
            }
        }
        // 最后还得处理一下
        maxLen = max(maxLen, size - start);
        return maxLen;
    }
};
