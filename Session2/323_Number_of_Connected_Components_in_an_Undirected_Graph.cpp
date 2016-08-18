class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> father(n);
        for(int i = 0; i < n; i ++)
            father[i] = i;
        for(auto edge:edges) {
            if(getFather(father, edge.first) != getFather(father, edge.second))
            //要把某一个的father连到另一个的father上，而不是把某一个连到另一个的father上
                father[father[edge.first]] = father[edge.second];
        }
        unordered_set<int> component;
        int count = 0;
        for(int i = 0; i < n; i ++) {
            int c = getFather(father, i);
            if(component.find(c) == component.end()) {
                component.insert(c);
                count ++;
            }
        }
        return count;
    }
    int getFather(vector<int>& father, int cur) {
        if(father[cur] == cur)
            return cur;
        father[cur] = getFather(father, father[cur]);
        return father[cur];
    }
};
