class Solution {
public:
    int longestPalindrome(string s) {
        int mp[52] = {0};
        int n = s.length();
        for(int i = 0; i < n; i ++) {
            if(s[i] >= 'a' && s[i] <= 'z')
                mp[s[i] - 'a'] ++;
            else
                mp[s[i] - 'A' + 26] ++;
        }
        bool hasOdd = false;
        int count = 0;
        for(int i = 0; i < 52; i ++) {
            if(mp[i] % 2 == 0)
                count += mp[i];
            else if(!hasOdd) {
                hasOdd = true;
                count += mp[i];
            }
            else {
                count += (mp[i] / 2 * 2);
            }
        }
        return count;
    }
};
