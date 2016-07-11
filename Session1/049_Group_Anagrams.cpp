class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashTable;
        sort(strs.begin(), strs.end());
        for(int i = 0; i < strs.size(); i ++) {
            string tmp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            hashTable[strs[i]].push_back(tmp);
        }
        vector<vector<string>> result;
        unordered_map<string, vector<string>>::iterator i = hashTable.begin();
        while(i != hashTable.end()) {
            result.push_back(i->second);
            i ++;
        }
        return result;
    }
};
