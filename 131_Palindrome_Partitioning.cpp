
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i <= j) {
            if(s[i] != s[j])
                return false;
            i ++;
            j --;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        getPath(s, path, res, 0);
        return res;
    }
    void getPath(string s, vector<string> path, vector<vector<string>>& res, int start) {
        if(s.length() == start) {
            res.push_back(path);
            return;
        }
        for(int i = start; i < s.length(); i ++) {
            string sub = s.substr(start, i - start + 1);
            if(isPalindrome(sub)) {
                path.push_back(sub);
                getPath(s, path, res, i + 1);
                path.pop_back();
            }
        }
    }
};
/*
此方法也能AC，就是比上面那个慢而已。。
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i <= j) {
            if(s[i] != s[j])
                return false;
            i ++;
            j --;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        getPath(s, path, res, 1);
        return res;
    }
    void getPath(string s, vector<string> path, vector<vector<string>>& res, int pos) {
        if(s.length() == 0) {
            res.push_back(path);
            return;
        }
        if(pos > s.length())
            return;
        string sub = s.substr(0, pos);
        if(isPalindrome(sub)) {
            path.push_back(sub);
            getPath(s.substr(pos), path, res, 1);
            path.pop_back();
        }
        getPath(s, path, res, pos + 1);
    }
};*/
