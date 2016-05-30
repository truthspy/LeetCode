/**
 * 看了https://leetcode.com/discuss/83824/7-lines-easy-java-solution写的
 */
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.length() == 0)
            return false;
        istringstream in(preorder);
        vector<string> tree;
        string val;
        while(getline(in, val, ','))
            tree.push_back(val);
        int diff = 1;
        int size = tree.size();
        for(int i = 0; i < size; i ++) {
            diff --;
            if(diff < 0)
                return false;
            if(tree[i] != "#")
                diff += 2;
        }
        return diff == 0;
    }
};
