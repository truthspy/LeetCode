// 只有入口和出口的入度不等于出度，所以从入口开始，当stuck的时候，找到的就是出口，然后再在前面加圈
// 所以最后要记着reverse结果
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> mp;
        int n = tickets.size();
        for(int i = 0; i < n; i ++) {
            if(mp.find(tickets[i].first) == mp.end()) {
                multiset<string> cur;
                mp[tickets[i].first] = cur;
            }
            mp[tickets[i].first].insert(tickets[i].second);
        }
        vector<string> res;
        visit("JFK", res, mp);
        reverse(res.begin(), res.end());
        return res;
    }
    void visit(string cur, vector<string>& res, unordered_map<string, multiset<string>>& mp) {
        while(!mp[cur].empty()) {
            string next = *mp[cur].begin();
            mp[cur].erase(mp[cur].begin());
            visit(next, res, mp);
        }
        res.push_back(cur);
    }
};
