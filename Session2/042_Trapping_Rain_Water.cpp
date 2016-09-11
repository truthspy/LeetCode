class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int res = 0;
        while(l < r) {
            int curMin = 0;
            if(height[l] <= height[r]) {
                curMin = height[l];
                while(l < r && height[l] <= curMin) {
                    res += (curMin - height[l]);
                    l ++;
                }
            }
            else {
                curMin = height[r];
                while(l < r && height[r] <= curMin) {
                    res += (curMin - height[r]);
                    r --;;
                }
            }
        }
        return res;
    }
};
