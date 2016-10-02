class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();
        if(n == 0)
            return 0;
        int i = 0;
        vector<string> path;
        int count = 0;
        string cur = "";
        int res = 0;
        while(i <= n) {
            if(i < n && input[i] != '\n') {
                cur += input[i];
                i ++;
            }
            else {
                if(count == 0) {
                    if(path.size() == 0)
                        path.push_back(cur);
                    else
                        path[0] = cur;
                }
                else {
                    cur = path[count - 1] + "/" + cur;
                    if(path.size() == count)
                        path.push_back(cur);
                    else
                        path[count] = cur;
                }
                if(cur.find('.') != string::npos)
                    res = max(res, (int)cur.length());
                cur = "";
                if(i == n)
                    break;
                i ++;
                count = 0;
                while(i < n && input[i] == '\t') {
                    count ++;
                    i ++;
                }
            }
        }
        return res;
    }
};
