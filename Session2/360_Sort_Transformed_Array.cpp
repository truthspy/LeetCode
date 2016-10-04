// 写得有点复杂，别人的方法简单：
// 抛物线如果开口朝上，两边的值比中间大，否则两边的值最小
// 那么可以两个指针从两头开始扫，如果开口朝上，则把大的加到队尾，如果开口朝下，则把小的加入队首
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> res;
        if(n == 0)
            return res;
        double mid = -0.5 * (double) b / (double) a;
        int pos = 0;
        while(pos < n && nums[pos] < mid)
            pos ++;
        reverse(nums.begin(), nums.begin() + pos);
        int i = 0;
        int j = pos;
        while(i < pos && j < n) {
            if((mid * 2.0 - (double)nums[i]) <= (double)nums[j]) {
                res.push_back(nums[i]);
                i ++;
            }
            else {
                res.push_back(nums[j]);
                j ++;
            }
        }
        while(i < pos) {
            res.push_back(nums[i]);
            i ++;
        }
        while(j < n) {
            res.push_back(nums[j]);
            j ++;
        }
        for(int i = 0; i < n; i ++) {
            res[i] = a * res[i] * res[i] + b * res[i] + c;
        }
        // 要注意a<0的情况
        if(a < 0)
            reverse(res.begin(), res.end());
        return res;
    }
};
