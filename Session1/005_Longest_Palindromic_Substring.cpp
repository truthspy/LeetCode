class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int maxL,maxR;
        int maxLen = 0;
        for(int i = 0; i < len; i ++)  {
            int l = i;
            int r = i;
            int count = 0;
            while(l >= 0 && r < len && s[l] == s[r]) {
                if(l == r)
                    count ++;
                else
                    count += 2;
                l --;
                r ++;
            }
            if(count > maxLen) {
                maxL = l + 1;
                maxR = r - 1;
                maxLen = count;
            }
            l = i;
            r = i + 1;
            count = 0;
            while(l >= 0 && r < len && s[l] == s[r]) {
                l --;
                r ++;
                count += 2;
            }
            if(count > maxLen) {
                maxL = l + 1;
                maxR = r - 1;
                maxLen = count;
            }
        }
        return s.substr(maxL, maxLen);
    }
};
//TODO
//动归O(n^2)
//Manacher’s Algorithm, 复杂度 O(n)
