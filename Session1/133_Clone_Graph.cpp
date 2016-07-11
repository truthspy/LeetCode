/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
/**
 * TODO
 * 1. DFS方法
 * 2. BFS方法可以用一个oldNode和newNode对应的hashtable，这样就不用建两个队列了。
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode*> ht;

        if(node == NULL)
            return NULL;
        queue<UndirectedGraphNode*> graph;
        queue<UndirectedGraphNode*> oldGraph;
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        graph.push(newNode);
        oldGraph.push(node);
        ht[newNode->label] = newNode;

        while(!graph.empty()) {
            UndirectedGraphNode *curNode = graph.front();
            graph.pop();
            UndirectedGraphNode *curOldNode = oldGraph.front();
            oldGraph.pop();
            int curSize= (curOldNode->neighbors).size();
            for(int i = 0; i < curSize; i ++) {
                int neighborLabel = (curOldNode->neighbors)[i]->label;
                if(ht.find(neighborLabel) != ht.end()) {
                    (curNode->neighbors).push_back(ht[neighborLabel]);
                }
                else {
                    UndirectedGraphNode *tmp = new UndirectedGraphNode(neighborLabel);
                    (curNode->neighbors).push_back(tmp);
                    ht[neighborLabel] = tmp;
                    graph.push(tmp);
                    oldGraph.push((curOldNode->neighbors)[i]);
                }
            }
        }
        return newNode;
    }
};
