class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pre;
        vector<int> current;
        current.push_back(1);
        for(int i = 1; i <= rowIndex; i ++) {
            pre = current;
            current.clear();
            current.push_back(1);
            for(int j = 1; j < i; j ++) {
                current.push_back(pre[j - 1] + pre[j]);
            }
            current.push_back(pre[i - 1]);
        }
        return current;
    }
};
