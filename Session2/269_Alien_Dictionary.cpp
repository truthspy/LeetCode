class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> mp;
        vector<int> inDegree(26, -1);
        int n = words.size();
        for(int i = 0; i < n; i ++) {
            int pos = 0;
            if(i != 0) {
                while(pos < words[i - 1].size() && pos < words[i].size()) {
                    if(inDegree[words[i][pos] - 'a'] == -1) {
                        inDegree[words[i][pos] - 'a'] = 0;
                        vector<char> cur;
                        mp[words[i][pos]] = cur;
                    }
                    if(words[i - 1][pos] == words[i][pos])
                        pos ++;
                    else {
                        inDegree[words[i][pos] - 'a'] ++;
                        mp[words[i - 1][pos]].push_back(words[i][pos]);
                        pos ++;
                        break;
                    }
                }
                // 短的要在长的前面，不然返回空！
                // 同时还得再判断一下最后一位是不是一样的！
                if(pos == words[i].size() && pos < words[i - 1].size()) {
                    if(pos == 0 || words[i][pos - 1] == words[i - 1][pos - 1])
                        return "";
                }
            }
            while(pos < words[i].size()) {
                if(inDegree[words[i][pos] - 'a'] == -1) {
                    inDegree[words[i][pos] - 'a'] = 0;
                    vector<char> cur;
                    mp[words[i][pos]] = cur;
                }
                pos ++;
            }
        }
        int count = 0;
        string res = "";
        queue<char> q;
        for(int i = 0; i < 26; i ++) {
            if(inDegree[i] >= 0)
                count ++;
            if(inDegree[i] == 0)
                q.push(i + 'a');
        }
        while(!q.empty()) {
            char cur = q.front();
            q.pop();
            res += cur;
            vector<char> next = mp[cur];
            for(int i = 0; i < next.size(); i ++) {
                inDegree[next[i] - 'a'] --;
                if(inDegree[next[i] - 'a'] == 0)
                    q.push(next[i]);
            }
        }
        if(count != res.size())
            return "";
        return res;
    }
};
