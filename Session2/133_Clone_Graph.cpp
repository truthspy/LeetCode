/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
// 1. DFS newnode->neighbors.push_back(dfs(oldNode->neighbors[i]))
// 2. BFS 可以在加入队列的时候复制，而不是弹出的时候，这样就可以一次性找到新复制节点的所有neighbor，不用再遍历一遍
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        while(!q.empty()) {
            UndirectedGraphNode* cur = q.front();
            q.pop();
            if(mp.find(cur) != mp.end())
                continue;
            UndirectedGraphNode* copy = new UndirectedGraphNode(cur->label);
            mp[cur] = copy;
            for(auto nodes : cur->neighbors)
                q.push(nodes);
        }
        for(auto nodePair : mp) {
            UndirectedGraphNode* old = nodePair.first;
            UndirectedGraphNode* copy = nodePair.second;
            for(auto oldNode : old->neighbors)
                copy->neighbors.push_back(mp[oldNode]);
        }
        return mp[node];
    }
};
