class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        int total = m * n;
        vector<int> father(total);
        for(int i = 0; i < total; i ++)
            father[i] = i;
        int count = 0;
        int size = positions.size();
        vector<int> res;
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i = 0; i < size; i ++) {
            int x = positions[i].first;
            int y = positions[i].second;
            grid[x][y] = 1;
            count ++;
            for(int j = 0; j < 4; j ++) {
                int xx = x + dir[j][0];
                int yy = y + dir[j][1];
                if(xx < 0 || yy < 0 || xx >= m || yy >= n)
                    continue;
                if(grid[xx][yy] == 0)
                    continue;
                int f1 = findFather(x * n + y, father);
                int f2 = findFather(xx * n + yy, father);
                if(f1 != f2) {
                    count --;
                    father[f1] = f2;
                }
            }
            res.push_back(count);
        }
        return res;
    }
    int findFather(int x, vector<int>& father) {
        if(father[x] == x)
            return x;
        father[x] = findFather(father[x], father);
        return father[x];
    }
};
