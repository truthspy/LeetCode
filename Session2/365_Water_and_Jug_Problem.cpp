// 数学解法。。。。抄来的。。。
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z)
            return false;
        if(x == z || y == z || x + y == z)
            return true;
        return z % gcd(x, y) == 0;
    }
    int gcd(int x, int y) {
        while(y != 0) {
            int tmp = y;
            y = x % y;
            x = tmp;
        }
        return x;
    }
};
/* BFS超时
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        set<pair<int,int>> mp;
        // vector<vector<bool>> visited(x + 1, vector<bool>(y + 1, false));
        queue<pair<int,int>> q;
        q.push(make_pair(0, 0));
        mp.insert(make_pair(0, 0));
        while(!q.empty()) {
            int curX = q.front().first;
            int curY = q.front().second;
            q.pop();
            if(curX == z || curY == z || curX + curY == z)
                return true;
            if(curX > 0 && mp.find(make_pair(0, curY)) == mp.end()) {
                if(curY == z)
                    return true;
                mp.insert(make_pair(0, curY));
                q.push(make_pair(0, curY));
            }
            if(curY > 0 && mp.find(make_pair(curX, 0)) == mp.end()) {
                if(curX == z)
                    return true;
                mp.insert(make_pair(curX, 0));
                q.push(make_pair(curX, 0));
            }
            if(curX < x && mp.find(make_pair(x, curY)) == mp.end()) {
                if(curY == z || x + curY == z)
                    return true;
                mp.insert(make_pair(x, curY));
                q.push(make_pair(x, curY));
            }
            if(curY < y && mp.find(make_pair(curX, y)) == mp.end()) {
                if(curX == z || curX + y == z)
                    return true;
                mp.insert(make_pair(curX, y));
                q.push(make_pair(curX, y));
            }
            int diffX = x - curX;
            int diffY = y - curY;
            if(curX >= diffY && mp.find(make_pair(curX-diffY, y)) == mp.end()) {
                if(curX - diffY == z || curX - diffY + y == z)
                    return true;
                mp.insert(make_pair(curX-diffY, y));
                q.push(make_pair(curX-diffY, y));
            }
            else if(curX < diffY && mp.find(make_pair(0, curY + curX)) == mp.end()) {
                mp.insert(make_pair(0, curY + curX));
                q.push(make_pair(0, curY + curX));
            }
            if(curY >= diffX && mp.find(make_pair(x, curY - diffX)) == mp.end()) {
                if(curY - diffX == z || x + curY - diffX == z)
                    return true;
                mp.insert(make_pair(x, curY - diffX));
                q.push(make_pair(x, curY - diffX));
            }
            else if(curY < diffX && mp.find(make_pair(curX + curY, 0)) == mp.end()) {
                mp.insert(make_pair(curX + curY, 0));
                q.push(make_pair(curX + curY, 0));
            }
        }
        return false;
    }
};
*/
