class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> degree(n, 0);
        vector<vector<int>> outEdges(n);
        int size = edges.size();
        for(auto edge:edges) {
            degree[edge.first] ++;
            degree[edge.second] ++;
            outEdges[edge.first].push_back(edge.second);
            outEdges[edge.second].push_back(edge.first);
        }
        queue<int> q;
        for(int i = 0; i < n; i ++) {
            // 要注意==0的节点
            if(degree[i] == 1 || degree[i] == 0)
                q.push(i);
        }
        int count = n;
        while(count > 2) {
            int size = q.size();
            //要一次把上一层的节点都弹出来
            while(size > 0) {
                size --;
                int cur = q.front();
                q.pop();
                count --;
                for(int i = 0; i < outEdges[cur].size(); i ++) {
                    degree[outEdges[cur][i]] --;
                    if(degree[outEdges[cur][i]] == 1)
                        q.push(outEdges[cur][i]);
                }
            }
        }
        vector<int> res;
        while(!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
