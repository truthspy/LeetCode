// Set&Map用红黑树实现
// unordered_set&unordered_map用哈希表实现，对pair没有哈希函数，不能直接用

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        set<pair<int,int>> mp;
        int n = points.size();
        int minX = INT_MAX;
        int maxX = INT_MIN;
        for(int i = 0; i < n; i ++) {
            mp.insert(points[i]);
            minX = min(minX, points[i].first);
            maxX = max(maxX, points[i].first);
        }
        int mid = minX + maxX;
        for(int i = 0; i < n; i ++) {
            int x = points[i].first;
            int y = points[i].second;
            if(mp.find(make_pair(mid - x, y)) == mp.end())
                return false;
        }
        return true;
    }
};
