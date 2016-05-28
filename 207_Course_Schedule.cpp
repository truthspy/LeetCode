class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adjGraph(numCourses);
        int edgeSize = prerequisites.size();
        for(int i = 0; i < edgeSize; i ++) {
            int l = prerequisites[i].first;
            int r = prerequisites[i].second;
            adjGraph[l].push_back(r);
            inDegree[r] ++;
        }
        queue<int> nodes;
        for(int i = 0; i < numCourses; i ++) {
            if(inDegree[i] == 0)
                nodes.push(i);
        }
        int total = 0;
        while(!nodes.empty()) {
            total ++;
            int cur = nodes.front();
            nodes.pop();
            int curSize = adjGraph[cur].size();
            for(int i = 0; i < curSize; i ++) {
                inDegree[adjGraph[cur][i]] --;
                if(inDegree[adjGraph[cur][i]] == 0)
                    nodes.push(adjGraph[cur][i]);
            }
        }
        return (total == numCourses);
    }
};
