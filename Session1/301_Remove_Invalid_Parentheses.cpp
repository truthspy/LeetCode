/**
 * 看了答案的BFS
 * 为何速度这么慢
 */
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        unordered_map<string, int> mp;
        vector<string> result;
        q.push(s);
        mp[s] = 1;
        while(!q.empty()) {
            int size = q.size();
            bool found = false;
            while(size > 0) {
                size --;
                string cur = q.front();
                q.pop();
                if(isValid(cur)) {
                    result.push_back(cur);
                    found = true;
                }
                if(found)
                    continue;
                int len = cur.length();
                for(int i = 0; i < len; i ++) {
                    if(cur[i] == '(' || cur[i] == ')') {
                        string tmp = cur.substr(0, i) + cur.substr(i + 1);
                        if(mp.find(tmp) == mp.end()) {
                            q.push(tmp);
                            mp[tmp] = 1;
                        }
                    }
                }
            }
            if(found)
                break;
        }
        return result;
    }
    bool isValid(string s) {
        int len = s.length();
        int left = 0;
        for(int i = 0; i < len; i ++) {
            if(s[i] == '(')
                left ++;
            else if(s[i] == ')') {
                left --;
                if(left < 0)
                    return false;
            }
        }
        if(left != 0)
            return false;
        return true;
    }
};
