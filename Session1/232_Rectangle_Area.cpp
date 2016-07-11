//这题看discuss写的
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);
        
        int left = max(A,E);
        int right = min(C,G);
        int bottom = max(B,F);
        int top = min(D,H);
        
        int overlap = 0;
        if(right > left && top > bottom)
            overlap = (right - left) * (top - bottom);
        int area = area1 + area2 - overlap;
        return area;
    }
};
