class Solution {
public:
    string simplifyPath(string path) {
        string cur = "";
        int i = 0;
        stack<string> s;
        while(i <= path.size()) {
            if(i == path.size() || path[i] == '/') {
                if(cur == "..") {
                    if(!s.empty())
                        s.pop();
                }
                else if(cur != "." && cur != "")
                    s.push(cur);
                cur = ""; //只要碰到'/'就要归为空
            }
            else
                cur += path[i];
            i ++;
        }
        if(s.empty())
            return "/";
        string res = "";
        while(!s.empty()) {
            res = ("/" + s.top()) + res;
            s.pop();
        }
        return res;
    }
};
