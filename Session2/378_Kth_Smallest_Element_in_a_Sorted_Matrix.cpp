// 先想navie的方法！！用最大堆求第k小的数，遍历一遍
class Solution {
public:
    struct Element {
        int val;
        int x;
        int y;
        Element(int a, int b, int c) {
            val = a;
            x = b;
            y = c;
        }
    };
    struct mycmp {
        bool operator()(const Element& a, const Element& b) {
            return a.val > b.val;
        }
    };
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<Element, vector<Element>, mycmp> pq;
        int n = matrix.size();
        for(int i = 0; i < n; i ++) {
            Element ele(matrix[i][0], i, 0);
            pq.push(ele);
        }
        int count = 1;
        while(count < k) {
            count ++;
            Element ele = pq.top();
            pq.pop();
            if(ele.y != n - 1) {
                Element next(matrix[ele.x][ele.y + 1], ele.x, ele.y + 1);
                pq.push(next);
            }
        }
        return pq.top().val;
    }
};
