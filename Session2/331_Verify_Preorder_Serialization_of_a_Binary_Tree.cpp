// @TODO
// Another Method: 用出度入度判断，每个非叶子节点贡献一个入度，两个出度，叶子节点只贡献一个入度，初始为根节点加一个入度，这样就只要保证入度等于出度就可以
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int> s;
        while(preorder != "") {
            int pos = preorder.find(',');
            string cur = "";
            if(pos == string::npos) {
                cur = preorder;
                preorder = "";
            }
            else {
                cur = preorder.substr(0, pos);
                preorder = preorder.substr(pos + 1);
            }
            if(cur == "#") {
                if(preorder == "" && s.empty())
                    return true;
                if(s.empty()) 
                    return false;
                s.pop();
            }
            else
                s.push(atoi(cur.c_str()));
        }
        return false;
    }
};
