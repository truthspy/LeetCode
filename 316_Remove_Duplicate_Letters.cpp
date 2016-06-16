/**
 * 还是花花给我讲的
 */
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> mp;
        unordered_map<char, int> visited;
        int len = s.length();
        for(int i = 0; i < len; i ++) {
            mp[s[i]] ++;
            visited[s[i]] = 0;
        }
        string res = "";
        
        for(int i = 0; i < len; i ++) {
            if(visited[s[i]]) {
                mp[s[i]] --;
                continue;
            }
            int pos = res.length() - 1;
            while(pos >= 0) {
                if(res[pos] > s[i] && mp[res[pos]]) {
                    visited[res[pos]] = 0;
                    res.erase(pos);
                    pos --;
                }
                else
                    break;
            }
            res += s[i];
            visited[s[i]] = 1;
            mp[s[i]] --;
        }
        return res;
    }
};
