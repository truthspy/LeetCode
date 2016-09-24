class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> outEdges(numCourses);
        for(int i = 0; i < prerequisites.size(); i ++) {
            inDegree[prerequisites[i].first] ++;
            outEdges[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i ++) {
            if(inDegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        vector<int> res;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            count ++;
            res.push_back(cur);
            for(int i = 0; i < outEdges[cur].size(); i ++) {
                inDegree[outEdges[cur][i]] --;
                if(inDegree[outEdges[cur][i]] == 0)
                    q.push(outEdges[cur][i]);
            }
        }
        if(count != numCourses)
            res.clear();
        return res;
    }
};
