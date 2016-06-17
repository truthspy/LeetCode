/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
/**
 * 对于每一个点A，计算其他点到它的斜率
 * 每层循环中，用一个map，保存每个斜率出现的次数，找出现次数最多的一个
 * 同时，要注意如果循环中，有点B与A坐标相同，那么记录相同的点数，最后加到次数最多的一个上
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int size = points.size();
        if(size <= 2)
            return size;
        int maxNum = 0;
        for(int i = 0; i < size; i ++) {
            int sameNum = 1;
            unordered_map<float, int> mp;
            int nonExists = 0;
            for(int j = 0; j < size; j ++) {
                if(j == i)
                    continue;
                if(points[j].x == points[i].x && points[j].y == points[i].y) {
                    sameNum ++;
                    continue;
                }
                if(points[j].x == points[i].x)
                    nonExists ++;
                else {
                    int diffX = points[i].x - points[j].x;
                    int diffY = points[i].y - points[j].y;
                    float slope = (float)diffY / (float)diffX;
                    mp[slope] ++;
                }
            }
            int curMaxNum = nonExists;
            for(auto num:mp) {
                curMaxNum = max(curMaxNum, num.second);
            }
            curMaxNum += sameNum;
            maxNum = max(curMaxNum, maxNum);
        }
        return maxNum;
    }
};
