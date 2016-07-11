/**
 * 看discuss之后写的
 * 一直走直到stuck，然后再在其前面加环
 * 可能有重复，要用multiset
 * TODO
 * 再仔细想想
 */
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        
        vector<string> result;
        unordered_map<string, multiset<string>> graph;
        int size = tickets.size();
        for(int i = 0; i < size; i ++) {
            string from = tickets[i].first;
            string to = tickets[i].second;
            graph[from].insert(to);
        }
        visit("JFK", result, graph);
        reverse(result.begin(), result.end());
        return result;
    }
    void visit(string city, vector<string>& result, unordered_map<string, multiset<string>>& graph) {
        while(!graph[city].empty()) {
            string nextCity = *(graph[city].begin());
            graph[city].erase(graph[city].begin());
            visit(nextCity, result, graph);
        }
        result.push_back(city);
    }
};
