//TODO: DFS Method
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        const int INF = 2147483647;
        int n = rooms.size();
        if(n == 0)
            return;
        int m = rooms[0].size();
        int total = m * n;
        vector<bool> visited(total, false);
        //vector<int> minStep(total, INF);
        queue<int> toVisit;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                if(rooms[i][j] == 0) {
                    int cur = i * m + j;
                    toVisit.push(cur);
                }
            }
        }
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!toVisit.empty()) {
            int pos = toVisit.front();
            toVisit.pop();
            if(visited[pos])
                continue;
            int y = pos % m;
            int x = pos / m;
            for(int i = 0; i < 4; i ++) {
                int xx = x + dir[i][0];
                int yy = y + dir[i][1];
                if(xx >= n || xx < 0 || yy >= m || yy < 0)
                    continue;
                if(rooms[xx][yy] == -1)
                    continue;
                rooms[xx][yy] = min(rooms[xx][yy], rooms[x][y] + 1);
                int nextPos = xx * m + yy;
                toVisit.push(nextPos);
                visited[pos] = true;
            }
        }
    }
};
