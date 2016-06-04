class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string path = "";
        findIp(s, path, result, 0, 0);
        return result;
    }
    void findIp(string s, string path, vector<string>& result, int start, int num) {
        if(num == 4) {
            if(start == s.length())
                result.push_back(path);
            return;
        }
        string curPath = path;
        for(int i = 0; i < 3; i ++) {
            if(s.substr(start).length() < (i + 1))
                return;
            string sub = s.substr(start, i + 1);
            if(sub[0] == '0' && i != 0) //防止出现"0.00.01.1"这种情况
                return;
            int ip = stoi(sub);
            if(ip <= 255 && ip >= 0) {
                curPath += sub;
                if(num != 3)
                    curPath += ".";
                findIp(s, curPath, result, start + i + 1, num + 1);
                curPath = path;
            }
        }
    }
};
