class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int size = words.size();
        if(size == 0)
            return result;
        int len = words[0].length();
        int total = 0;
        unordered_map<string, int> dict;
        unordered_map<string, int> mp;
        for(int i = 0; i < size; i ++) {
            dict[words[i]] ++;
        }
        int l = 0;
        int r = 0;
        int maxL = s.length() - len * size;
        while(l <= maxL) {
            string sub = s.substr(r, len);
            if(dict.find(sub) != dict.end()) {
                if(mp.find(sub) == mp.end() || mp[sub] < dict[sub]) { 
                    mp[sub] ++;
                    r += len;
                    total ++;
                    if(total != size)
                        continue;
                    else
                        result.push_back(l);
                }
            }
            total = 0;
            l ++;
            r = l;
            mp.clear();
        }
        return result;
    }
};
