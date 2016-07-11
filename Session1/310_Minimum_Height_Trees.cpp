/**
 * 思路from：http://www.cnblogs.com/grandyang/p/5000291.html
 */
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> result;
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        int edgeNum = edges.size();
        for(int i = 0; i < edgeNum; i ++) {
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
            indegree[edges[i].first] ++;
            indegree[edges[i].second] ++;
        }
        queue<int> leaf;
        for(int i = 0; i < n; i ++) {
            if(indegree[i] <= 1)
                leaf.push(i);
        }
        while(n > 2) {          //重要！！！！！！！！！
            int curSize = leaf.size();
            while(curSize > 0) {
                curSize --;
                int next = leaf.front();
                leaf.pop();
                n --;
                for(int i = 0; i < graph[next].size(); i ++) {
                    indegree[graph[next][i]] --;
                    if(indegree[graph[next][i]] == 1)
                        leaf.push(graph[next][i]);
                }
            }
        }
        while(!leaf.empty()) {
            result.push_back(leaf.front());
            leaf.pop();
        }
        return result;
    }
};
