class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> res;
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i ++)
            mp[words[i]] = i;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < words[i].size(); j ++) {
                string sub1 = words[i].substr(0, j);
                string sub2 = words[i].substr(j);
                if(isPalindrome(sub1)) {
                    reverse(sub2.begin(), sub2.end());
                    if(mp.find(sub2) != mp.end() && mp[sub2] != i) {
                        res.push_back({mp[sub2], i}); //顺序也要注意！sub1和sub2不一样
                    }
                    // 因为如果下面的判断里sub2是回文的，那么sub2的reverse也是回文的，所以不用再转回来
                }
                if(isPalindrome(sub2)) {
                    reverse(sub1.begin(), sub1.end());
                    if(mp.find(sub1) != mp.end() && mp[sub1] != i) {
                        res.push_back({i, mp[sub1]}); // 顺序！！！
                        // 同时还要考虑本身字符串是回文，并且有空串的情况！！！
                        if(j == 0)
                            res.push_back({mp[sub1], i});
                    }
                }
            }
        }
        return res;
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i ++;
            j --;
        }
        return true;
    }
};
