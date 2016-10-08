class Solution {
private:
    string one[3] = {"0","1","8"};
    string two[4][2] = {{"1","1"},{"8","8"},{"6","9"},{"9","6"}};
public:
    vector<string> findStrobogrammatic(int n) {
        return find(n, n);
    }
    vector<string> find(int n, int total) {
        vector<string> res;
        if(n == 0) {
            res.push_back("");
            return res;
        }
        if(n == 1) {
            for(int i = 0; i < 3; i ++)
                res.push_back(one[i]);
            return res;
        }
        vector<string> pre = find(n - 2, total);
        for(int i = 0; i < pre.size(); i ++) {
            if(n != total)
                res.push_back("0" + pre[i] + "0");
            for(int j = 0; j < 4; j ++) {
                res.push_back(two[j][0] + pre[i] + two[j][1]);
            }
        }
        return res;
    }
};
