/**
 * 思路from discuss
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int top = 0;
        int size = height.size();
        int pos = 0;
        for(int i = 0; i < size; i ++) {
            if(height[i] > top) {
                top = height[i];
                pos = i;
            }
        }
        int trappedWater = 0;
        int curMax = 0;
        for(int i = 0; i < pos ; i ++) {
            if(height[i] >= curMax)
                curMax = height[i];
            else
                trappedWater += (curMax - height[i]);
        }
        curMax = 0;
        for(int i = size - 1; i > pos; i --) {
            if(height[i] >= curMax)
                curMax = height[i];
            else
                trappedWater += (curMax - height[i]);
        }
        return trappedWater;
    }
};

//TODO
//只扫一遍即可
