class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> res;
        vector<pair<int,int>> height;
        for(int i = 0; i < buildings.size(); i ++) {
            height.push_back(make_pair(buildings[i][0], -buildings[i][2]));
            height.push_back(make_pair(buildings[i][1], buildings[i][2]));
        }
        sort(height.begin(), height.end());
        multiset<int> h;
        int preH = 0;
        h.insert(0); //先插入一个0！！
        for(int i = 0; i < height.size(); i ++) {
            int key = height[i].first;
            int value = height[i].second;
            if(value < 0)
                h.insert(-value);
            else
                h.erase(h.find(value)); //不能直接h.erase(value)，不然可能会删除所有=value的值
            int curH = *(h.rbegin());
            if(curH != preH) {
                res.push_back(make_pair(key, curH));
                preH = curH;
            }
        }
        return res;
    }
};
