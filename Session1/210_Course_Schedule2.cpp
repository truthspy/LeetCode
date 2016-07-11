class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> result;
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        int edgeSize = prerequisites.size();
        for(int i = 0; i < edgeSize; i ++) {
            int first = prerequisites[i].second;
            int second = prerequisites[i].first;
            inDegree[second] ++;
            graph[first].push_back(second);
        }
        queue<int> order;
        for(int i = 0; i < numCourses; i ++) {
            if(inDegree[i] == 0)
                order.push(i);
        }
        while(!order.empty()) {
            int cur = order.front();
            order.pop();
            result.push_back(cur);
            int curSize = graph[cur].size();
            for(int i = 0; i < curSize; i ++) {
                inDegree[graph[cur][i]] --;
                if(inDegree[graph[cur][i]] == 0)
                    order.push(graph[cur][i]);
            }
        }
        if(result.size() != numCourses)
            result.clear();
        return result;
    }
};
