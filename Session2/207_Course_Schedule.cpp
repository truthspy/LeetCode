class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int size = prerequisites.size();
        if(size == 0)
            return true;
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for(int i = 0; i < size; i ++) {
            inDegree[prerequisites[i].first] ++;
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        queue<int> nonPreQueue;
        int out = 0;
        for(int i = 0; i < numCourses; i ++) {
            if(inDegree[i] == 0) {
                nonPreQueue.push(i);
                out ++;
            }
        }
        while(!nonPreQueue.empty()) {
            int cur = nonPreQueue.front();
            nonPreQueue.pop();
            for(int i = 0; i < graph[cur].size(); i ++) {
                inDegree[graph[cur][i]] --;
                if(inDegree[graph[cur][i]] == 0) {
                    nonPreQueue.push(graph[cur][i]);
                    out ++;
                }
            }
        }
        return (out == numCourses);
    }
};
