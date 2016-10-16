class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int len = 0;
        int start = 0;
        for(int i = 0; i < n; i ++) {
            if(len + words[i].size() + (i - start) > maxWidth) {
                res.push_back(connect(start, i - 1, words, maxWidth));
                start = i;
                len = 0;
            }
            len += words[i].size();
        }
        string lastLine = "";
        for(int i = start; i < n; i ++) {
            lastLine += words[i];
            if(i != n - 1)
                lastLine += " ";
        }
        while(lastLine.size() != maxWidth) {
            lastLine += " ";
        }
        res.push_back(lastLine);
        return res;
    }
    string connect(int l, int r, vector<string>& words, int maxWidth) {
        string res = "";
        int len = 0;
        for(int i = l; i <= r; i ++)
            len += words[i].size();
        int space = maxWidth - len;
        int cnt = r - l;
        if(cnt == 0) {
            res += words[l];
            while(res.size() < maxWidth)
                res += " ";
            return res;
        }
        int spaceNum = space / cnt;
        int remain = space % cnt;
        string curSpace = "";
        while(spaceNum > 0) {
            curSpace += " ";
            spaceNum --;
        }
        for(int i = l; i <= r; i ++) {
            res += words[i];
            if(i != r)
                res += curSpace;
            if(remain > 0) {
                res += " ";
                remain --;
            }
        }
        return res;
    }
};
