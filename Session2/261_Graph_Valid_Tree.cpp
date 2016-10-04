class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> father(n);
        for(int i = 0; i < n; i ++)
            father[i] = i;
        int size = edges.size();
        if(size != n - 1)
            return false;
        for(int i = 0; i < size; i ++) {
            int firstFather = getFather(edges[i].first, father);
            int secondFather = getFather(edges[i].second, father);
            if(firstFather == secondFather)
                return false;
            father[secondFather] = firstFather;
        }
        return true;
    }
    int getFather(int x, vector<int> &father) {
        if(father[x] == x)
            return x;
        int v = getFather(father[x], father);
        father[x] = v;
        return v;
    }
};
