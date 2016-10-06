class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, vector<pair<string, double>>> mp;
        int n = equations.size();
        for(int i = 0; i < n; i ++) {
            string a = equations[i].first;
            string b = equations[i].second;
            if(mp.find(a) == mp.end()) {
                vector<pair<string, double>> curA;
                mp[a] = curA;
            }
            if(a == b)
                continue;
            if(mp.find(b) == mp.end()) {
                vector<pair<string, double>> curB;
                mp[b] = curB;
            }
            mp[a].push_back(make_pair(b, values[i]));
            mp[b].push_back(make_pair(a, 1.0 / values[i]));
        }
        int size = queries.size();
        vector<double> res;
        for(int i = 0; i < size; i ++) {
            string a = queries[i].first;
            string b = queries[i].second;
            if(mp.find(a) == mp.end() || mp.find(b) == mp.end())
                res.push_back(-1.0);
            else if(a == b)
                res.push_back(1.0);
            else {
                queue<pair<string, double>> q;
                unordered_set<string> visited;
                q.push(make_pair(a, 1.0));
                visited.insert(a);
                while(!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    if(cur.first == b) {
                        res.push_back(cur.second);
                        break;
                    }
                    else {
                        auto next = mp[cur.first];
                        for(int j = 0; j < next.size(); j ++) {
                            if(visited.find(next[j].first) == visited.end()) {
                                visited.insert(next[j].first);
                                double divRes = cur.second * next[j].second;
                                q.push(make_pair(next[j].first, divRes));
                                mp[a].push_back(make_pair(next[j].first, divRes));
                                mp[next[j].first].push_back(make_pair(a, 1.0 / divRes));
                            }
                        }
                    }
                }
                if(res.size() == i)
                    res.push_back(-1.0);
            }
        }
        return res;
    }
};
