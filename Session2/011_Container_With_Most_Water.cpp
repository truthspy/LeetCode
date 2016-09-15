class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int l = 0;
        int r = height.size() - 1;
        while(l < r) {
            if(height[l] <= height[r]) {
                res = max(height[l] * (r - l), res);
                l ++;
            }
            else {
                res = max(height[r] * (r - l), res);
                r --;
            }
        }
        return res;
    }
};
